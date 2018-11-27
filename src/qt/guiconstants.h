// Copyright (c) 2011-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_QT_GUICONSTANTS_H
#define SOLBIT_QT_GUICONSTANTS_H

/* Milliseconds between model updates */
static const int MODEL_UPDATE_DELAY1 = 500;
static const int MODEL_UPDATE_DELAY2 = 5000;

/* AskPassphraseDialog -- Maximum passphrase length */
static const int MAX_PASSPHRASE_SIZE = 1024;

/* SolbitGUI -- Size of icons in status bar */
static const int STATUSBAR_ICONSIZE = 16;

static const bool DEFAULT_CHOOSE_DATADIR = false;
static const bool DEFAULT_SELFSIGNED_ROOTCERTS = false;
static const bool DEFAULT_SPLASHSCREEN = true;

static const std::string DEFAULT_UIPLATFORM =
#if defined(Q_OS_MAC)
    "macosx"
#elif defined(Q_OS_WIN)
    "windows"
#else
    "other"
#endif
    ;


/* Invalid field background style */
#define STYLE_INVALID "background:#FF8080"

/* Transaction list -- unconfirmed transaction */
#define COLOR_UNCONFIRMED QColor(128, 128, 128)
/* Transaction list -- negative amount */
#define COLOR_NEGATIVE QColor(255, 0, 0)
/* Transaction list -- bare address (without label) */
#define COLOR_BAREADDRESS QColor(140, 140, 140)
/* Transaction list -- TX status decoration - open until date */
#define COLOR_TX_STATUS_OPENUNTILDATE QColor(64, 64, 255)
/* Transaction list -- TX status decoration - offline */
#define COLOR_TX_STATUS_OFFLINE QColor(192, 192, 192)
/* Transaction list -- TX status decoration - default color */
#define COLOR_BLACK QColor(0, 0, 0)

/* Tooltips longer than this (in characters) are converted into rich text,
   so that they can be word-wrapped.
 */
static const int TOOLTIP_WRAP_THRESHOLD = 80;

/* Maximum allowed URI length */
static const int MAX_URI_LENGTH = 255;

/* QRCodeDialog -- size of exported QR Code image */
#define QR_IMAGE_SIZE 350

/* Number of frames in spinner animation */
#define SPINNER_FRAMES 36

#define QAPP_ORG_NAME "Solbit"
#define QAPP_ORG_NAME_LEGACY "Solbit"
#define QAPP_ORG_DOMAIN "solbit.info"
#define QAPP_APP_NAME_DEFAULT "Solbit-Qt"
#define QAPP_APP_NAME_TESTNET "Solbit-Qt-testnet"
#define QAPP_APP_NAME_NOLNET "Solbit-Qt-nolimit" // BU
#define QAPP_APP_NAME_BUCASH "Solbit-Qt-BUcash"

#endif // SOLBIT_QT_GUICONSTANTS_H
