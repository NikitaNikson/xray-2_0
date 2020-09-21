#include "pch.h"
#include "project_browser_dialog.h"
#include <xray/editor/base/images/folder_icons.h>
#include <xray/editor/base/images_loading.h>

using xray::editor_base::folders_icons;
namespace xray {
namespace editor {

ListViewItem^ create_folder_item(System::String^ name, System::String^ modif, System::String^ descr, int image_index)
{
	return gcnew ListViewItem(gcnew cli::array<System::String^>(3){name, modif, descr}, image_index);
}

System::String^ concate_path(System::String^ p1, System::String^ p2)
{
	System::String^ to_add = "";

	if(p1->Length && p2->Length && !p1->EndsWith("\\"))
		to_add		= "\\";

	return p1+to_add+p2;
}

void project_browser_dialog::in_constructor( )
{
	m_root_path				= nullptr;
	m_current_path			= nullptr;
	m_image_list_large		= xray::editor_base::image_loader::load_images("folder_icons64x64", 64, safe_cast<int>(xray::editor_base::folders_icons_count), this->GetType());
	m_image_list_small		= xray::editor_base::image_loader::load_images("folder_icons16x16", 16, safe_cast<int>(xray::editor_base::folders_icons_count), this->GetType());
	projects_list_view->LargeImageList = m_image_list_large;
	projects_list_view->SmallImageList = m_image_list_small;
}

void project_browser_dialog::initialize_dialog( bool b_save_mode, System::String^ resources_path, System::String^ focused_item )
{
	ok_button->Enabled				= false;
	m_b_save_project_mode			= b_save_mode;

	ASSERT							( focused_item );
	setup_resources_path			( resources_path );

	m_current_path					= "";
	
	if( focused_item->Contains("/"))
		m_current_path				= System::IO::Path::GetDirectoryName( focused_item );

	fill_current_path				( );

	System::String^ last_name		= System::IO::Path::GetFileNameWithoutExtension( focused_item );
	
	if( last_name && projects_list_view->Items->ContainsKey(last_name) )
		projects_list_view->Items[last_name]->Selected = true;
}

void project_browser_dialog::setup_resources_path( System::String^ path )
{
	m_root_path = concate_path(IO::Path::GetFullPath(path), "projects");
}

::DialogResult project_browser_dialog::SelectProjectToLoad( System::String^ resources_path, System::String^ focused_item )
{
	initialize_dialog			( false, resources_path, focused_item );
	return						ShowDialog();
}

::DialogResult project_browser_dialog::SelectProjectToSave( System::String^ resources_path, System::String^ focused_item )
{
	initialize_dialog			( true, resources_path, focused_item );
	return						ShowDialog();
}

bool project_browser_dialog::check_valid_xray_project(System::String^ folder)
{
	if(m_b_save_project_mode)
	{
		System::String^ fn = concate_path(folder, "project.xprj" );
		return System::IO::File::Exists( fn );
	}else
	{
		System::String^ fn = concate_path(folder, "project.xprj" );
		return System::IO::File::Exists( fn );
	}
}

void project_browser_dialog::fill_current_path( )
{
	ListViewItem^ list_item					= nullptr;
	selected_text_box->Text					= "";
	projects_list_view->Items->Clear		( );
	
	System::String^ current_root			= concate_path( m_root_path, m_current_path );

	if(m_current_path->Length)
	{
		list_item = create_folder_item		("..", "", "", xray::editor_base::navigate_back_img);
		projects_list_view->Items->Add		( list_item );
	}
	current_path_label->Text				= current_root;

	cli::array<System::String^>^ folders	= System::IO::Directory::GetDirectories( current_root );
	
	for each(System::String^ folder in folders)
	{
		String^ item					= System::IO::Path::GetFileNameWithoutExtension( folder );
		if(item->Length)
		{
			bool b_xray_project			= check_valid_xray_project( folder );
			System::DateTime dt			= System::IO::Directory::GetLastWriteTime( folder );
			if(b_xray_project)
			{
				list_item = create_folder_item(item, dt.ToString(), "xray project folder", xray::editor_base::xray_project_folder_img);
				projects_list_view->Items->Add	( list_item);
			}else
			{
				list_item = create_folder_item(item, dt.ToString(), "folder", xray::editor_base::folder_img);
				projects_list_view->Items->Add	( list_item );
			}
			
			list_item->Name	= item;
		}
	}
}

void project_browser_dialog::projects_list_view_ItemActivate(System::Object^, System::EventArgs^)
{
	ListViewItem^ activated_item = selected_list_item();

	if(activated_item==nullptr)
		return;


	if(activated_item->ImageIndex==xray::editor_base::folder_img)
	{
		browse_down( activated_item->Text );
	}else
	if(activated_item->ImageIndex==xray::editor_base::navigate_back_img)
	{
		browse_back();
	}else
	if(activated_item->ImageIndex==xray::editor_base::xray_project_folder_img && ok_button->Enabled)
	{
		ok_clicked( nullptr, nullptr );
	}
}

void project_browser_dialog::projects_list_view_SelectedIndexChanged(System::Object^, System::EventArgs^)
{
	if(selected_text_box->Focused)
		return;

	ListViewItem^ activated_item	= selected_list_item();
	if(activated_item!=nullptr)
	{
		if(activated_item->ImageIndex==xray::editor_base::navigate_back_img)
		{
			selected_text_box->Text	= "";
			return;
		}

		selected_text_box->Text		= activated_item->Text;
	}else
		selected_text_box->Text		= "";
}

void project_browser_dialog::browse_down( System::String^ folder )
{
	m_current_path		= concate_path( m_current_path, folder );
	fill_current_path	();
}

void project_browser_dialog::browse_back( )
{
	System::String^ new_current = System::IO::Path::GetDirectoryName( m_current_path );
	R_ASSERT					( new_current );

	m_current_path				= new_current;
	fill_current_path			( );
}

void project_browser_dialog::selected_text_box_TextChanged(System::Object^, System::EventArgs^)
{
	ok_button->Enabled				= false;

	if(selected_text_box->Focused)
	{ //user types
		if( projects_list_view->Items->ContainsKey(selected_text_box->Text) )
		{
			ListViewItem^ itm = projects_list_view->Items[selected_text_box->Text];
			if(!itm->Selected)
				itm->Selected = true;
		}else
		{//remove selection
				ListViewItem^ activated_item	= selected_list_item();
				if(activated_item)
					activated_item->Selected	= false;
		}
	}else
	{ // from selection changed event

	}

	if(selected_text_box->Text->Length == 0)
		return;

	if(m_b_save_project_mode)
	{ // saving mode
		int bad_idx = selected_text_box->Text->IndexOfAny(System::IO::Path::GetInvalidFileNameChars());
		if(-1 != bad_idx)
			return;

		ok_button->Enabled		= true;
	}else
	{ // loading mode
		ListViewItem^ activated_item	= selected_list_item();
		
		if(activated_item && activated_item->ImageIndex==xray::editor_base::xray_project_folder_img)
			ok_button->Enabled		= true;
	}
}

void project_browser_dialog::ok_clicked( System::Object^, System::EventArgs^)
{
	System::String^ selected		= concate_path(m_current_path, selected_text_box->Text);

	if(m_b_save_project_mode)
	{ // saving
		System::String^ fullpath	= concate_path(m_root_path, selected);
		if( !System::IO::Directory::Exists(fullpath) )
		{	// create question
			::DialogResult result = MessageBox::Show( m_editor_ide->wnd(), "Project directory \n'" 
														+ fullpath
														+ "'\n does not exist. Create new?", "XRay Editor"
														, MessageBoxButtons::OKCancel
														, MessageBoxIcon::Question );
			if(result==::DialogResult::OK)
			{
				System::IO::Directory::CreateDirectory	(fullpath);
			}else
				return;
		}
	}else
	{ // loading
	}

	selected_project				= selected->Replace("\\", "/");
	DialogResult					= ::DialogResult::OK;
}

void project_browser_dialog::cancel_clicked( System::Object^, System::EventArgs^)
{
	DialogResult = ::DialogResult::Cancel;
}

void project_browser_dialog::selected_text_box_KeyDown(System::Object^, System::Windows::Forms::KeyEventArgs^  e)
{
	if(e->KeyCode==System::Windows::Forms::Keys::Return)
		if(ok_button->Enabled)
			ok_clicked(nullptr, nullptr);
}

ListViewItem^ project_browser_dialog::selected_list_item( )
{
	return (projects_list_view->SelectedItems->Count) ? projects_list_view->SelectedItems[0] : nullptr;
}

} // namespace xray
} // namespace editor
