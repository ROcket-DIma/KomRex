//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "FileCtrl.hpp"
#include <sqlite3.h>
#include <fstream>
#include "Factory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
FileSystem File;
char const *db_name = "Databases.db";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	VirtualStringTree1->NodeDataSize =sizeof(TreeNodeStruct);
	myTread2=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
	if(myTread2!=NULL)
		myTread2->Terminate();
	File.ClosedHandle();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1OpenClick(TObject *Sender)
{
	Factory Factory;

	UnicodeString Dir = "C:\\";
	if (SelectDirectory("Выбор диска:","",Dir))
	Label2->Caption = Dir;

	Dir[Dir.Length()]='\0';
	UnicodeString str="\\\\.\\"+Dir;
	wchar_t *fileName=str.t_str();

	File=Factory.CaseFS(fileName);
	File.ViewInfo(Label1);

	Button3Sign->Visible=true;
	Edit2->Visible=true;
	Edit3->Visible=true;
	ClustMode->Visible=true;

	Label17->Visible=true;
	Label18->Visible=true;
	Label10->Visible=true;
	Label20->Visible=true;

	if(File.CountClust==0)
		Button3Sign->Enabled=false;
	else
		Button3Sign->Enabled=true;
	}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2DelStrClick(TObject *Sender)
{
	PVirtualNode numstr =  VirtualStringTree1->GetFirstSelected();

	if(numstr==NULL)
	 {
		return;
	 }

	TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(numstr);
	AnsiString str="DELETE from FILE where id = "+(AnsiString)nodeData->clusterNum +" ;";
	WorkToDB(str);
	ReloadViewDB();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3SignClick(TObject *Sender)
{
	ofstream out(db_name);
	out.close();
	AnsiString str = "CREATE TABLE FILE (ID INT NOT NULL, NAME TEXT NOT NULL);";
	sqlite3 *db;

	if ( sqlite3_open(db_name,&db))
	{
		ShowMessage("Не получается открыть БД: " + (String)sqlite3_errmsg(db));
		sqlite3_close(db);
	}

	sqlite3_exec(db, str.c_str(), NULL, 0,NULL);

	myTread2=new Thread2(File,false);
	VirtualStringTree1->Visible=true;
	Button2DelStr->Visible=true;
	Button4ClearDB->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4ClearDBClick(TObject *Sender)
{
		 AnsiString str="DELETE from FILE;";
		 WorkToDB(str);
		 VirtualStringTree1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (Edit1->Text == "Wien" || Edit1->Text == "Vena" || Edit1->Text == "wien"|| Edit1->Text == "vena")
	{
		Button1Open->Visible = true;
		Label2->Visible=true;
		Label9->Visible=true;
		Label19->Visible=true;
		Label11->Visible=true;

		Label3->Visible=false;
		Label4->Visible=false;
		Label5->Visible=false;
		Label6->Visible=false;
		Label7->Visible=false;
		Label15->Visible=false;
		Label16->Visible=false;
		Label14->Visible=false;
		Edit1->Visible=false;
		Button1->Visible=false;

		ShowMessage("Здравствуйте, администратор!\nРазработчик данной программы - Иванов Роман.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)
{
  TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(Node);
	switch (Column) {
		case 0:
		{
		  CellText=nodeData->clusterNum;
		  break;
		}
	case 1:
		{
		  CellText=nodeData->name;
		  break;
		}
	}
}
//---------------------------------------------------------------------------
void TForm1::ReloadViewDB()
{
	VirtualStringTree1->Clear();
	VirtualStringTree1->BeginUpdate();
	AnsiString str="Select * from FILE ;";

	sqlite3 *db;
	sqlite3_stmt *pStmt;
	int rc,coln,i,j;

	if ( sqlite3_open(db_name,&db))
	{
		ShowMessage("Не получается открыть БД: " + (String)sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	if (sqlite3_prepare(db, str.c_str(), -1, &pStmt, NULL))
	{
		sqlite3_finalize(pStmt);
		sqlite3_close(db);
	}

	while((rc = sqlite3_step(pStmt)) == SQLITE_ROW)
	{
		PVirtualNode entryNode = VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
		TreeNodeStruct *nodeData = (TreeNodeStruct*) VirtualStringTree1->GetNodeData(entryNode);
		coln = sqlite3_data_count(pStmt);
		for(j=0; j<coln; j++)

		{
			AnsiString otwet;
			otwet.printf("%s",sqlite3_column_text(pStmt, j));

				  switch (j) {
					case 0:
					  {
						  nodeData->clusterNum =otwet.ToInt();;
						  break;
					  }
					case 1:
					  {
						  nodeData->name = UnicodeString(otwet);
						  break;
					  }
				  }
		}
	}
	sqlite3_finalize(pStmt);
	sqlite3_close(db);
	VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------

void TForm1::WorkToDB(AnsiString str){

		sqlite3 *db;

		if ( sqlite3_open(db_name,&db))
		{
			ShowMessage("Не получается открыть БД: ");
			ShowMessage(sqlite3_errmsg(db));
			sqlite3_close(db);
		}

		if (sqlite3_exec(db, str.c_str(), NULL, 0,NULL))
		{
			sqlite3_close(db);
		}
		sqlite3_close(db);
}
//---------------------------------------------------------------------------



