#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T10:59:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = perspicientia
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        gui.cpp

HEADERS  += gui.h \
    thirdparty/poppler/include/cpp/poppler-document.h \
    thirdparty/poppler/include/cpp/poppler-embedded-file.h \
    thirdparty/poppler/include/cpp/poppler-font.h \
    thirdparty/poppler/include/cpp/poppler-global.h \
    thirdparty/poppler/include/cpp/poppler-image.h \
    thirdparty/poppler/include/cpp/poppler-page-renderer.h \
    thirdparty/poppler/include/cpp/poppler-page-transition.h \
    thirdparty/poppler/include/cpp/poppler-page.h \
    thirdparty/poppler/include/cpp/poppler-rectangle.h \
    thirdparty/poppler/include/cpp/poppler-toc.h \
    thirdparty/poppler/include/cpp/poppler-version.h \
    thirdparty/poppler/include/fofi/FoFiBase.h \
    thirdparty/poppler/include/fofi/FoFiEncodings.h \
    thirdparty/poppler/include/fofi/FoFiIdentifier.h \
    thirdparty/poppler/include/fofi/FoFiTrueType.h \
    thirdparty/poppler/include/fofi/FoFiType1.h \
    thirdparty/poppler/include/fofi/FoFiType1C.h \
    thirdparty/poppler/include/glib/poppler-action.h \
    thirdparty/poppler/include/glib/poppler-annot.h \
    thirdparty/poppler/include/glib/poppler-attachment.h \
    thirdparty/poppler/include/glib/poppler-date.h \
    thirdparty/poppler/include/glib/poppler-document.h \
    thirdparty/poppler/include/glib/poppler-enums.h \
    thirdparty/poppler/include/glib/poppler-features.h \
    thirdparty/poppler/include/glib/poppler-form-field.h \
    thirdparty/poppler/include/glib/poppler-layer.h \
    thirdparty/poppler/include/glib/poppler-media.h \
    thirdparty/poppler/include/glib/poppler-movie.h \
    thirdparty/poppler/include/glib/poppler-page.h \
    thirdparty/poppler/include/glib/poppler-structure-element.h \
    thirdparty/poppler/include/glib/poppler.h \
    thirdparty/poppler/include/goo/FixedPoint.h \
    thirdparty/poppler/include/goo/gfile.h \
    thirdparty/poppler/include/goo/gmem.h \
    thirdparty/poppler/include/goo/GooHash.h \
    thirdparty/poppler/include/goo/GooLikely.h \
    thirdparty/poppler/include/goo/GooList.h \
    thirdparty/poppler/include/goo/GooMutex.h \
    thirdparty/poppler/include/goo/GooString.h \
    thirdparty/poppler/include/goo/GooTimer.h \
    thirdparty/poppler/include/goo/grandom.h \
    thirdparty/poppler/include/goo/gstrtod.h \
    thirdparty/poppler/include/goo/gtypes.h \
    thirdparty/poppler/include/goo/ImgWriter.h \
    thirdparty/poppler/include/goo/JpegWriter.h \
    thirdparty/poppler/include/goo/NetPBMWriter.h \
    thirdparty/poppler/include/goo/PNGWriter.h \
    thirdparty/poppler/include/goo/TiffWriter.h \
    thirdparty/poppler/include/qt5/poppler-annotation.h \
    thirdparty/poppler/include/qt5/poppler-export.h \
    thirdparty/poppler/include/qt5/poppler-form.h \
    thirdparty/poppler/include/qt5/poppler-link-private.h \
    thirdparty/poppler/include/qt5/poppler-link.h \
    thirdparty/poppler/include/qt5/poppler-media.h \
    thirdparty/poppler/include/qt5/poppler-optcontent.h \
    thirdparty/poppler/include/qt5/poppler-page-transition.h \
    thirdparty/poppler/include/qt5/poppler-qt5.h \
    thirdparty/poppler/include/splash/Splash.h \
    thirdparty/poppler/include/splash/SplashBitmap.h \
    thirdparty/poppler/include/splash/SplashClip.h \
    thirdparty/poppler/include/splash/SplashErrorCodes.h \
    thirdparty/poppler/include/splash/SplashFont.h \
    thirdparty/poppler/include/splash/SplashFontEngine.h \
    thirdparty/poppler/include/splash/SplashFontFile.h \
    thirdparty/poppler/include/splash/SplashFontFileID.h \
    thirdparty/poppler/include/splash/SplashFTFont.h \
    thirdparty/poppler/include/splash/SplashFTFontEngine.h \
    thirdparty/poppler/include/splash/SplashFTFontFile.h \
    thirdparty/poppler/include/splash/SplashGlyphBitmap.h \
    thirdparty/poppler/include/splash/SplashMath.h \
    thirdparty/poppler/include/splash/SplashPath.h \
    thirdparty/poppler/include/splash/SplashPattern.h \
    thirdparty/poppler/include/splash/SplashScreen.h \
    thirdparty/poppler/include/splash/SplashState.h \
    thirdparty/poppler/include/splash/SplashT1Font.h \
    thirdparty/poppler/include/splash/SplashT1FontEngine.h \
    thirdparty/poppler/include/splash/SplashT1FontFile.h \
    thirdparty/poppler/include/splash/SplashTypes.h \
    thirdparty/poppler/include/splash/SplashXPath.h \
    thirdparty/poppler/include/splash/SplashXPathScanner.h \
    thirdparty/poppler/include/Annot.h \
    thirdparty/poppler/include/Array.h \
    thirdparty/poppler/include/BuiltinFont.h \
    thirdparty/poppler/include/BuiltinFontTables.h \
    thirdparty/poppler/include/CachedFile.h \
    thirdparty/poppler/include/Catalog.h \
    thirdparty/poppler/include/CharCodeToUnicode.h \
    thirdparty/poppler/include/CharTypes.h \
    thirdparty/poppler/include/CMap.h \
    thirdparty/poppler/include/CompactFontTables.h \
    thirdparty/poppler/include/DateInfo.h \
    thirdparty/poppler/include/Decrypt.h \
    thirdparty/poppler/include/Dict.h \
    thirdparty/poppler/include/Error.h \
    thirdparty/poppler/include/ErrorCodes.h \
    thirdparty/poppler/include/FileSpec.h \
    thirdparty/poppler/include/FontEncodingTables.h \
    thirdparty/poppler/include/FontInfo.h \
    thirdparty/poppler/include/Form.h \
    thirdparty/poppler/include/Function.h \
    thirdparty/poppler/include/Gfx.h \
    thirdparty/poppler/include/GfxFont.h \
    thirdparty/poppler/include/GfxState.h \
    thirdparty/poppler/include/GfxState_helpers.h \
    thirdparty/poppler/include/GlobalParams.h \
    thirdparty/poppler/include/Hints.h \
    thirdparty/poppler/include/JArithmeticDecoder.h \
    thirdparty/poppler/include/JBIG2Stream.h \
    thirdparty/poppler/include/Lexer.h \
    thirdparty/poppler/include/Linearization.h \
    thirdparty/poppler/include/Link.h \
    thirdparty/poppler/include/LocalPDFDocBuilder.h \
    thirdparty/poppler/include/MarkedContentOutputDev.h \
    thirdparty/poppler/include/Movie.h \
    thirdparty/poppler/include/NameToCharCode.h \
    thirdparty/poppler/include/NameToUnicodeTable.h \
    thirdparty/poppler/include/Object.h \
    thirdparty/poppler/include/OptionalContent.h \
    thirdparty/poppler/include/Outline.h \
    thirdparty/poppler/include/OutputDev.h \
    thirdparty/poppler/include/Page.h \
    thirdparty/poppler/include/PageTransition.h \
    thirdparty/poppler/include/Parser.h \
    thirdparty/poppler/include/PDFDoc.h \
    thirdparty/poppler/include/PDFDocBuilder.h \
    thirdparty/poppler/include/PDFDocEncoding.h \
    thirdparty/poppler/include/PDFDocFactory.h \
    thirdparty/poppler/include/poppler-config.h \
    thirdparty/poppler/include/PopplerCache.h \
    thirdparty/poppler/include/PreScanOutputDev.h \
    thirdparty/poppler/include/ProfileData.h \
    thirdparty/poppler/include/PSOutputDev.h \
    thirdparty/poppler/include/PSTokenizer.h \
    thirdparty/poppler/include/Rendition.h \
    thirdparty/poppler/include/SecurityHandler.h \
    thirdparty/poppler/include/SignatureInfo.h \
    thirdparty/poppler/include/Sound.h \
    thirdparty/poppler/include/SplashOutputDev.h \
    thirdparty/poppler/include/StdinCachedFile.h \
    thirdparty/poppler/include/StdinPDFDocBuilder.h \
    thirdparty/poppler/include/Stream-CCITT.h \
    thirdparty/poppler/include/Stream.h \
    thirdparty/poppler/include/StructElement.h \
    thirdparty/poppler/include/StructTreeRoot.h \
    thirdparty/poppler/include/TextOutputDev.h \
    thirdparty/poppler/include/UnicodeCClassTables.h \
    thirdparty/poppler/include/UnicodeCompTables.h \
    thirdparty/poppler/include/UnicodeDecompTables.h \
    thirdparty/poppler/include/UnicodeMap.h \
    thirdparty/poppler/include/UnicodeMapTables.h \
    thirdparty/poppler/include/UnicodeTypeTable.h \
    thirdparty/poppler/include/UTF.h \
    thirdparty/poppler/include/UTF8.h \
    thirdparty/poppler/include/ViewerPreferences.h \
    thirdparty/poppler/include/XpdfPluginAPI.h \
    thirdparty/poppler/include/XRef.h

FORMS    += gui.ui


# INCLUDEPATH += thirdparty/poppler/include

# LIBS += -L/usr/include/poppler/qt5 -lpoppler-qt5
unix|win32: LIBS += -lpoppler-qt5

DISTFILES += \
    thirdparty/poppler/lib/libpoppler-cpp.so \
    thirdparty/poppler/lib/libpoppler-cpp.so.0 \
    thirdparty/poppler/lib/libpoppler-cpp.so.0.3.0 \
    thirdparty/poppler/lib/libpoppler-glib.so \
    thirdparty/poppler/lib/libpoppler-glib.so.8 \
    thirdparty/poppler/lib/libpoppler-glib.so.8.8.0 \
    thirdparty/poppler/lib/libpoppler-qt5.so \
    thirdparty/poppler/lib/libpoppler-qt5.so.1 \
    thirdparty/poppler/lib/libpoppler-qt5.so.1.9.0 \
    thirdparty/poppler/lib/libpoppler.so \
    thirdparty/poppler/lib/libpoppler.so.66 \
    thirdparty/poppler/lib/libpoppler.so.66.0.0
