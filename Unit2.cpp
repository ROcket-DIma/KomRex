//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include <sqlite3.h>
#include <typeinfo>

#include "Unit2.h"
#include "Unit1.h"

#include "ZDecorator.h"
#include "Signature.h"

#pragma package(smart_init)

unsigned long count;
__fastcall Thread2::Thread2(FileSystem file,bool CreateSuspended)
	: TThread(CreateSuspended)
{
	File=file;
}
//---------------------------------------------------------------------------
void __fastcall Thread2::Execute()
{
	count=0;

	Form1->Button3Sign->Enabled=false;
	Form1->Button1Open->Enabled=false;
	char* db_name = "Databases.db";

	sqlite3 *db;

	if ( sqlite3_open(db_name,&db))
	{
		sqlite3_close(db);
	}

	Iterator iterator=Iterator(File);

	if(Form1->ClustMode->ItemIndex==1)
	iterator=ZDecorator(iterator);

	if(File.CountClust!=0)
	{
		if(Form1->Edit2->Text=="")
			iterator.Zero();
		else
			iterator.MyPosition(StrToLong(Form1->Edit2->Text));

		if(Form1->Edit3->Text=="")
			iterator.End();
		else
			iterator.UPosition(StrToLong(Form1->Edit3->Text));

		byte *dataBuffer = new byte[File.ClustSize];
		Signature check;

		for(;!iterator.Never();iterator.Next()){

		 if(iterator.CurrPosition(dataBuffer))
			{
				UnicodeString type=check.FSign(dataBuffer);
				count++;

				if(count%10000==0)
					Synchronize(&UpdateTable);

				if(type!="NON")
				{
					AnsiString sql="INSERT INTO FILE (ID, NAME) VALUES ("+(AnsiString)iterator.GetPosition()+", \""+type+"\" );";
					sqlite3_exec(db, sql.c_str(), NULL, 0,NULL);
				}

			 }
		}
		delete[] dataBuffer;
	}

	sqlite3_close(db);
	Synchronize(&End);
    ShowMessage("Поиск файлов завершен.\nПроверьте базу данных.");
}
//---------------------------------------------------------------------------
void __fastcall Thread2::UpdateTable()
{
  Form1->ReloadViewDB();
}
void __fastcall Thread2::End()
{
  Form1->Button3Sign->Enabled=true;
  Form1->Button1Open->Enabled=true;
  Form1->ReloadViewDB();
}
//---------------------------------------------------------------------------
