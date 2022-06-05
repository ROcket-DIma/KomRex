// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VirtualTrees.StyleHooks.pas' rev: 32.00 (Windows)

#ifndef Virtualtrees_StylehooksHPP
#define Virtualtrees_StylehooksHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <Winapi.UxTheme.hpp>
#include <System.Classes.hpp>
#include <System.UITypes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Themes.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Controls.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Virtualtrees
{
namespace Stylehooks
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TVclStyleScrollBarsHook;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TVclStyleScrollBarsHook : public Vcl::Forms::TScrollingStyleHook
{
	typedef Vcl::Forms::TScrollingStyleHook inherited;
	
	
private:
	class DELPHICLASS TScrollWindow;
	#pragma pack(push,8)
	class PASCALIMPLEMENTATION TScrollWindow : public Vcl::Controls::TWinControl
	{
		typedef Vcl::Controls::TWinControl inherited;
		
	private:
		TVclStyleScrollBarsHook* FStyleHook;
		bool FVertical;
		HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Msg);
		HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TMessage &Msg);
		HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Msg);
		
	public:
		__fastcall virtual TScrollWindow(System::Classes::TComponent* AOwner);
		__property TVclStyleScrollBarsHook* StyleHook = {read=FStyleHook, write=FStyleHook};
		__property bool Vertical = {read=FVertical, write=FVertical, nodefault};
	public:
		/* TWinControl.CreateParented */ inline __fastcall TScrollWindow(HWND ParentWindow) : Vcl::Controls::TWinControl(ParentWindow) { }
		/* TWinControl.Destroy */ inline __fastcall virtual ~TScrollWindow(void) { }
		
	};
	
	#pragma pack(pop)
	
	
private:
	TScrollWindow* FHorzScrollWnd;
	bool FLeftMouseButtonDown;
	TScrollWindow* FVertScrollWnd;
	System::Types::TPoint __fastcall NCMousePosToClient(const System::Types::TPoint &P);
	MESSAGE void __fastcall CMUpdateVclStyleScrollbars(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Msg);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall WMKeyUp(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Msg);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDown(Winapi::Messages::TWMMouse &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCMouseMove(Winapi::Messages::TWMMouse &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonUp(Winapi::Messages::TWMMouse &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Winapi::Messages::TWMMouse &Msg);
	HIDESBASE MESSAGE void __fastcall WMMouseWheel(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Winapi::Messages::TWMScroll &Msg);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Winapi::Messages::TWMScroll &Msg);
	HIDESBASE MESSAGE void __fastcall WMCaptureChanged(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDblClk(Winapi::Messages::TWMMouse &Msg);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TMessage &Msg);
	HIDESBASE MESSAGE void __fastcall WMMove(Winapi::Messages::TMessage &Msg);
	MESSAGE void __fastcall WMPosChanged(Winapi::Messages::TMessage &Msg);
	HIDESBASE void __fastcall InitScrollBars(void);
	
protected:
	virtual void __fastcall CalcScrollBarsRect(void);
	virtual void __fastcall DrawHorzScrollBar(HDC DC);
	virtual void __fastcall DrawVertScrollBar(HDC DC);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall PaintScroll(void);
	bool __fastcall PointInTreeHeader(const System::Types::TPoint &P);
	HIDESBASE void __fastcall UpdateScroll(void);
	
public:
	__fastcall virtual TVclStyleScrollBarsHook(Vcl::Controls::TWinControl* AControl);
	__fastcall virtual ~TVclStyleScrollBarsHook(void);
	__classmethod void __fastcall DrawExpandArrow(Vcl::Graphics::TBitmap* pBitmap, bool pExpanded, System::Uitypes::TColor pColor = (System::Uitypes::TColor)(0x1fffffff));
	__property HorzScrollRect;
	__property VertScrollRect;
};

#pragma pack(pop)

typedef Vcl::Themes::TCustomStyleServices* __fastcall (*TVTStyleServicesFunc)(Vcl::Controls::TControl* AControl/* = (Vcl::Controls::TControl*)(0x0)*/);

//-- var, const, procedure ---------------------------------------------------
static const System::Word CM_UPDATE_VCLSTYLE_SCROLLBARS = System::Word(0xb802);
extern DELPHI_PACKAGE TVTStyleServicesFunc VTStyleServicesFunc;
}	/* namespace Stylehooks */
}	/* namespace Virtualtrees */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_VIRTUALTREES_STYLEHOOKS)
using namespace Virtualtrees::Stylehooks;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_VIRTUALTREES)
using namespace Virtualtrees;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Virtualtrees_StylehooksHPP
