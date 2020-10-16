
// MFCApplication1.h : fichier d'en-tête principal de l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// symboles principaux


// CMFCApplication1App :
// Consultez MFCApplication1.cpp pour l'implémentation de cette classe
//

class CMFCApplication1App : public CWinApp
{
public:
	CMFCApplication1App();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication1App theApp;
