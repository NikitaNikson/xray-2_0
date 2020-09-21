#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "project_defines.h"

using xray::editor::wpf_controls::property_grid_host;

namespace xray {
namespace editor {
	class property_holder;
	ref class project;
	/// <summary>
	/// Summary for object_inspector_tab
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class object_inspector_tab : public  WeifenLuo::WinFormsUI::Docking::DockContent
	{
	public:
		object_inspector_tab()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			in_constructor();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~object_inspector_tab()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// object_inspector_tab
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(284, 476);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->HideOnClose = true;
			this->MinimumSize = System::Drawing::Size(50, 50);
			this->Name = L"object_inspector_tab";
			this->TabText = L"object inspector";
			this->Text = L"object inspector";
			this->TopMost = true;
			this->ResumeLayout(false);

		}
#pragma endregion
		private:
			void	in_constructor	();
		private:
			property_grid_host^		m_property_grid_host;
		public:
			void		show_properties(object_list^ objects);
	};
}
}