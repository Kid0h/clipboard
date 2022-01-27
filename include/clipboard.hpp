#pragma once
#include <string>
#include <Windows.h>

class Clipboard {
public:
    // Set clipboard's text
    static bool set_clipboard_text(const char* string, size_t length) {
        size_t size = length * sizeof(char);

		HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, size + 1 * sizeof(char));
        char* dst = (char*)GlobalLock(hMem);
		memcpy(dst, string, size); dst[length] = 0;
		GlobalUnlock(hMem);
		
		if (OpenClipboard(NULL)) {
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hMem);
            CloseClipboard();

            return true;
        }
        return false;
    }
    static bool set_clipboard_text(const std::string& string) {
		const char* data = string.c_str();
		size_t length = string.length();
        size_t size = length * sizeof(char);

		HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, size + 1 * sizeof(char));
        char* dst = (char*)GlobalLock(hMem);
		memcpy(dst, data, size); dst[length] = 0;
		GlobalUnlock(hMem);
		
		if (OpenClipboard(NULL)) {
            EmptyClipboard();
            SetClipboardData(CF_TEXT, hMem);
            CloseClipboard();

            return true;
        }
        return false;
	}
    static bool set_clipboard_text(const wchar_t* string, size_t length) {
        size_t size = length * sizeof(wchar_t);

		HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, size + 1 * sizeof(wchar_t));
        wchar_t* dst = (wchar_t*)GlobalLock(hMem);
		memcpy(dst, string, size); dst[length] = 0;
		GlobalUnlock(hMem);
		
		if (OpenClipboard(NULL)) {
            EmptyClipboard();
            SetClipboardData(CF_UNICODETEXT, hMem);
            CloseClipboard();

            return true;
        }
        return false;
    }
    static bool set_clipboard_text(const std::wstring& string) {
		const wchar_t* data = string.c_str();
		size_t length = string.length();
        size_t size = length * sizeof(wchar_t);

		HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, size + 1 * sizeof(wchar_t));
        wchar_t* dst = (wchar_t*)GlobalLock(hMem);
		memcpy(dst, data, size); dst[length] = 0;
		GlobalUnlock(hMem);
		
		if (OpenClipboard(NULL)) {
            EmptyClipboard();
            SetClipboardData(CF_UNICODETEXT, hMem);
            CloseClipboard();

            return true;
        }
        return false;
	}


    // Get clipboard's text
    static bool get_clipboard_text(std::string& string) {
        bool status = false;
        if (OpenClipboard(NULL)) {
            if (HANDLE data_handle = GetClipboardData(CF_TEXT)) {
                char* raw_data = (char*)GlobalLock(data_handle);
                string.assign(raw_data);
                GlobalUnlock(data_handle);
                status = true;
            }
            CloseClipboard();
        }

        return status;
    }
    static bool get_clipboard_text(std::wstring& string) {
        bool status = false;
        if (OpenClipboard(NULL)) {
            if (HANDLE data_handle = GetClipboardData(CF_UNICODETEXT)) {
                wchar_t* raw_data = (wchar_t*)GlobalLock(data_handle);
                string.assign(raw_data);
                GlobalUnlock(data_handle);
                status = true;
            }
            CloseClipboard();
        }
        
        return status;
    }
};