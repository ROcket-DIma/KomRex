//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include "VirtualTrees.hpp"
#include <Vcl.Grids.hpp>
#include <Vcl.Outline.hpp>
#include <Vcl.Samples.DirOutln.hpp>
#include <Vcl.ExtCtrls.hpp>


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button3Sign;
	TVirtualStringTree *VirtualStringTree1;
	TButton *Button1Open;
	TRadioGroup *ClustMode;
	TButton *Button2DelStr;
	TButton *Button4ClearDB;
	TLabel *Label2;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TButton *Button1;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	void __fastcall Button1OpenClick(TObject *Sender);
	void __fastcall Button3SignClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall Button2DelStrClick(TObject *Sender);
	void __fastcall Button4ClearDBClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);


private:

	void WorkToDB(AnsiString str);
    class Thread2 *myTread2;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    void ReloadViewDB();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct{

	unsigned long clusterNum;
	UnicodeString   name;

} TreeNodeStruct;
//---------------------------------------------------------------------------
#endif
