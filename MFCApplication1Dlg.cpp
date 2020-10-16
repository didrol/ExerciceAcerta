
// MFCApplication1Dlg.cpp : fichier d'implémentation
//

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue de CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_TOOLS_CALCULER, &CMFCApplication1Dlg::OnToolsCalculer)
END_MESSAGE_MAP()


// gestionnaires de messages de CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	CString empty = CString("");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(empty);
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(empty);
	GetDlgItem(IDC_STATIC)->SetWindowTextW(empty);
}


void CMFCApplication1Dlg::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu popup, *subMenu;

	popup.LoadMenu(IDR_MENU1);
	subMenu = popup.GetSubMenu(0);
	subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}


void CMFCApplication1Dlg::OnToolsCalculer()
{
	CString nb1, nb2, resultat;
	std::ofstream logfile;

	GetDlgItem(IDC_EDIT1)->GetWindowText(nb1);
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(nb2);
	resultat.Format(_T("%s + %s = %d"), nb1, nb2, _ttoi(nb1) + _ttoi(nb2));
	GetDlgItem(IDC_STATIC)->SetWindowTextW(resultat);

	logfile.open("exercice.log", std::ios_base::app);
	logfile << CT2A(resultat) << "\n";
	logfile.close();
}
