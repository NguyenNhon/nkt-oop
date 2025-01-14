
#ifndef __UTILS_H__
#define __UTILS_H__

#pragma comment( lib, "winmm.lib" )
#include "conio.h"
#include <windows.h>
#include<time.h>

//CONSTANSTs

#define WIDTH 250
#define HEIGH 100

//Keys
typedef enum GKeys
{
	KEY_A    =0x41,
	KEY_B    =0x42,
	KEY_C    =0x43,
	KEY_D    =0x44,
	KEY_E    =0x45,
	KEY_F    =0x46,
	KEY_G    =0x47,
	KEY_H    =0x48,
	KEY_I    =0x49,
	KEY_J    =0x4A,
	KEY_K    =0x4B,
	KEY_L    =0x4C,
	KEY_M    =0x4D,
	KEY_N    =0x4E,
	KEY_O    =0x4F,
	KEY_P    =0x50,
	KEY_Q    =0x51,
	KEY_R    =0x52,
	KEY_S    =0x53,
	KEY_T    =0x54,
	KEY_U    =0x55,
	KEY_V    =0x56,
	KEY_W    =0x57,
	KEY_X    =0x58,
	KEY_Y    =0x59,
	KEY_Z    =0x5A,
	KEY_LEFT    =VK_LEFT,
	KEY_RIGHT   =VK_RIGHT,
	KEY_UP      =VK_UP,
	KEY_DOWN    =VK_DOWN,
	KEY_ESC     =VK_ESCAPE,
	KEY_ENTER	=VK_RETURN,
	KEY_SPACE	=VK_SPACE,
	KEY_DELETE	=VK_DELETE,
} GKeys;

//màu sắc
typedef enum GColors
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
	LIGHT_BLACK,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_MAGENTA,
	LIGHT_YELLOW,
	LIGHT_WHITE,	
} GColors;

//hướng di chuyển
typedef enum GDirections
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
} GDirections;

//font Family
typedef enum GFontFamilys
{
	MODERN			=FF_MODERN,
	DECORATIVE		=FF_DECORATIVE,
	DONTCARE		=FF_DONTCARE,
	ROMAN			=FF_ROMAN,
	SCRIPT			=FF_SCRIPT,
	SWISS			=FF_SWISS,
} GFontFamilys;

struct CVector2D
{
	float x;
	float y;
};

//Hình chữ nhật
typedef struct GRectangle
{
	float x;
	float y;
	float width;
	float height;
} GRectangle;

//màu background và màu chữ
GColors g_BackgroundColor = GColors::BLACK;
GColors g_ForegroundColor = GColors::LIGHT_WHITE;

//tổng hợp của background color và foreground color
WORD g_ConsoleColor;

//Lưu những màu tạm thời được sử dụng, không phải màu cho dùng chung
GColors g_TempBackgroundColor = g_BackgroundColor;
GColors g_TempForegroundColor = g_ForegroundColor;

//Lưu màu tạm thời được sử dụng, không phải màu cho dùng chung (kết hợp của g_TempBackgroundColor và g_TempForegroundColor)
WORD g_TempColor;

//mảng buffer dùng để vẽ
CHAR_INFO g_ConsoleBuffer[WIDTH * HEIGH];

//mảng trạng thái của các phím
bool g_ArrKeys[256];

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//declare
void GSetNoScroolBar();
void GSetWindowPosition(int x, int y);
void GSetCursorVisiable(bool bIsVisiable = false);
void GSetFont(int fontWidth = 8, int fontHeight = 8,  int fontWeight = 100, GFontFamilys fontFamily = GFontFamilys::MODERN);
void GSetTextColor(GColors color);
void GSetBGColor(GColors color);
bool GIsKeyDown(int vkCode);
bool GIsKeyUp(int vkCode);
bool GIsKeyPress(GKeys vKey);
bool GIsKeyRelease(GKeys vKey);
bool GIsElapsed(long elapsedMilisecond);
float GGetFPS();
void GClearBuffer();
void GPutCharToBuffer(char c, int x, int y, GColors foregroundColor = g_ForegroundColor, GColors backgroundColor = g_BackgroundColor);
void GFlushBuffer();

int random(int a, int b)
{	
	return rand()%(b+1)+a;
}

int random(int a)
{
	if(rand()%2)
		return rand()%(a+1);
	return -rand()%(a+1);

}

//FUNCTIONs

//set no scroll bar
void GSetNoScroolBar()
{
	//set windows first, because can not set screen buffer's size bigger than window's size
	//set windows size
	SMALL_RECT windowSize = {0, 0, WIDTH - 1, HEIGH - 1};
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	
	//can not set buffer's size less than window's size
	//set buffersize
	COORD newSBSize;
	newSBSize.X = WIDTH;
	newSBSize.Y = HEIGH;
	SetConsoleScreenBufferSize(hConsole, newSBSize);

	//////////////////////////////////////////////////////////////////////////
	/// SET AGAIN FOR OK ///
	
	if(!SetConsoleWindowInfo(hConsole, TRUE, &windowSize))
	{
		MessageBox((HWND)hConsole, "Can not set Window Size!", "Error", MB_OK);
	}

	if(!SetConsoleScreenBufferSize(hConsole, newSBSize))
	{
		MessageBox((HWND)hConsole, "Can not set Screen Buffer Size!", "Error", MB_OK);
	}
}



//set vị trí cho cửa sổ
void GSetWindowPosition(int x, int y)
{
	HWND hWnd = GetConsoleWindow();
	MoveWindow(hWnd, x, y, WIDTH, HEIGH, TRUE);
}





// Ẩn hiện con trỏ nhấp nháy trong cửa sổ Console
void GSetCursorVisiable(bool bIsVisiable)
{
	CONSOLE_CURSOR_INFO cursor = {1, bIsVisiable};
	SetConsoleCursorInfo(hConsole, &cursor);
}




// Set font
//fontWidth = 8, fontHeight = 8 is the best way for game
//fontWeigh: 100 -> 1000
void GSetFont(int fontWidth, int fontHeight,  int fontWeight, GFontFamilys fontFamily)
{
	PCONSOLE_FONT_INFOEX lpFontInfo = new CONSOLE_FONT_INFOEX() ;
	
	// set the size of the CONSOLE_FONT_INFOEX
	lpFontInfo->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	// get the current value
	GetCurrentConsoleFontEx(hConsole, TRUE, lpFontInfo);	

	lpFontInfo->nFont = 2; //chỉ số của font trong list font console

	lpFontInfo->FontFamily = fontFamily;

	/*
	FontWeight
	The font weight. The weight can range from 100 to 1000, in multiples of 100. For example, the normal weight is 400, while 700 is bold.
	*/
	if(fontWeight >= 100 && fontWeight <= 1000)
	{
		lpFontInfo->FontWeight = fontWeight;
	}

	// set size to be 8x8, the default size is 8x16
	lpFontInfo->dwFontSize.X = fontWidth;
	lpFontInfo->dwFontSize.Y = fontHeight;

	// submit the settings
	SetCurrentConsoleFontEx(hConsole, 0, lpFontInfo);
}



//cài màu chữ
void GSetTextColor( GColors color )
{
	g_ForegroundColor = color;
	g_TempColor = g_ConsoleColor = (g_ConsoleColor & 0xF0) | (color & 0x0F);
	SetConsoleTextAttribute(
		hConsole,
		g_ConsoleColor
		);
}


//cài màu nền
void GSetBGColor( GColors color )
{
	g_BackgroundColor = color;

	g_TempColor = g_ConsoleColor = (g_ConsoleColor & 0x0F) | ((color & 0x0F) << 4);
	SetConsoleTextAttribute(
		hConsole,
		g_ConsoleColor
		);
}


//Kiểm tra trạng thái phím có đang down
bool GIsKeyDown(int vkCode)
{
	return (GetAsyncKeyState(vkCode) & 0x8000);
}



//Kiểm tra trạng thái phím có đang up
bool GIsKeyUp(int vkCode)
{
	return (!(GetAsyncKeyState(vkCode) & 0x8000));
}



//Kiểm tra xem có phím vKey vừa nhấn ko
bool GIsKeyPress(GKeys vKey)
{
	bool res = false;

	if(vKey < 0 || vKey > 255)
		return false;

	if(GetKeyState(vKey) & 0xff00)
	{
		if(g_ArrKeys[vKey] == false)
			res = true;
		else
			res = false;

		g_ArrKeys[vKey] = true;
	} 
	else
	{
		res = false;
		g_ArrKeys[vKey] = false;
	}

	return res;
}

//Kiểm tra xem có phím vKey vừa thả ra ko
bool GIsKeyRelease(GKeys vKey)
{
	bool res = false;

	if(vKey < 0 || vKey > 255)
		return false;

	if(GetKeyState(vKey) & 0xff00)
	{
		res = false;
		g_ArrKeys[vKey] = true;
	} 
	else
	{
		if(g_ArrKeys[vKey] == true)
			res = true;
		else
			res = false;

		g_ArrKeys[vKey] = false;
	}

	return res;
}
//các biến dùng cho hàm GIsElapsed
long g_lastTick = timeGetTime();
long g_currentTick = g_lastTick;

//kiểm tra xem đã qua thời gian elapsedMilisecond kể từ lần gọi trước chưa
bool GIsElapsed(long elapsedMilisecond)
{
	g_currentTick = timeGetTime();

	if(g_currentTick - g_lastTick >= elapsedMilisecond)
	{
		g_lastTick += elapsedMilisecond;
		return true;
	}
	else
	{
		return false;
	}
}

//các biến dùng để tính FPS, ko dùng để tính delta time
float g_fps;
long g_lastTick_fps = timeGetTime();
long g_currentTick_fps = g_lastTick_fps;

//get fps
float GGetFPS()
{
	long tmpLastTick_fps = g_lastTick_fps;
	g_lastTick_fps = g_currentTick_fps;
	g_currentTick_fps = timeGetTime();

	g_fps = (float)1000 / (float)(g_currentTick_fps - tmpLastTick_fps);

	return g_fps;
}

/*
 *This method draws the rectangle, no background
 *Usage:
 *GDrawRect(1,1,10,10);
 *or
 *GDrawRect(1,1,10,10,20,5);
 */
void GDrawRect(GRectangle rect, GColors borderColor)
{
	float x = rect.x;
	float y = rect.y;
	float width = rect.width;
	float height = rect.height;
	GColors colorBorder = borderColor;

	GPutCharToBuffer(char(178),x,y,colorBorder);

	for(int i = 1; i < width; i++)
	{
		GPutCharToBuffer(char(178),x+i,y,colorBorder);
	}

	GPutCharToBuffer(char(178),x + width,y,colorBorder);
	GPutCharToBuffer(char(178),x,y + height,colorBorder);
	
	for(int i = 1; i < width; i++)
		GPutCharToBuffer(char(178),x +i,y + height,colorBorder);

	GPutCharToBuffer(char(178),x + width,y + height,colorBorder);

	for(int i = 1; i < height ; i++)
	{
		GPutCharToBuffer(char(178),x,y+i,colorBorder);
		GPutCharToBuffer(char(178),x + width,y+i,colorBorder);
	}
}

/*Fill a rectangle
 *
 *Ex: GFillRect(0, 0, 10, 10, GColors::WHITE, GColors::BLACK);
 */
void GFillRect(GRectangle rect, GColors borderColor, GColors foreColor)
{
	float x = rect.x;
	float y = rect.y;
	float width = rect.width;
	float height = rect.height;
	GColors colorBorder = borderColor;
	GColors colorBG = foreColor;


	GPutCharToBuffer(char(178),x,y,colorBorder);

	for(int i = 1; i < width; i++)
	{
		GPutCharToBuffer(char(178),x+i,y,colorBorder);
	}

	for(int i = 1; i < width; i++)
	{
		for(int j = 1; j < height ; j++)
			GPutCharToBuffer(char(178),x+i,y+j,colorBG);
	}

	GPutCharToBuffer(char(178),x + width,y,colorBorder);
	GPutCharToBuffer(char(178),x,y + height,colorBorder);

	for(int i = 1; i < width; i++)
		GPutCharToBuffer(char(178),x +i,y + height,colorBorder);

	GPutCharToBuffer(char(178),x + width,y + height,colorBorder);

	for(int i = 1; i < height ; i++)
	{
		GPutCharToBuffer(char(178),x,y+i,colorBorder);
		GPutCharToBuffer(char(178),x + width,y+i,colorBorder);
	}
}

//kiểm tra 2 hình chữ nhật có va chạm nhau
//tức là có điểm chung nào hay ko
bool GIsIntersect(GRectangle a, GRectangle b)
{
	return !(a.x > b.x + b.width || a.x + a.width < b.x || a.y > b.y + b.height || a.y + a.height < b.y);
}

//Xóa hết buffer CHAR_INFO
void GClearBuffer()
{
	for (int y = 0; y < HEIGH; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			// An ANSI character is in the range 0-255,
			// so use % to keep it in this range.
			g_ConsoleBuffer[x + WIDTH * y].Char.AsciiChar = ' ';
			
			// The colour is also in the range 0-255,
			// as it is a pair of 4-bit colours.
			g_ConsoleBuffer[x + WIDTH * y].Attributes = g_ConsoleColor;
		}
	}
}

//Viết 1 ký tự lên buffer CHAR_INFO
void GPutCharToBuffer(char c, int x, int y, GColors foregroundColor, GColors backgroundColor)
{
	if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGH)
		return;

	// An ANSI character is in the range 0-255,
	// so use % to keep it in this range.
	g_ConsoleBuffer[x + WIDTH * y].Char.AsciiChar = c;


	if(foregroundColor != g_TempForegroundColor || backgroundColor != g_TempBackgroundColor )
	{
		g_TempForegroundColor = foregroundColor;
		g_TempBackgroundColor = backgroundColor;

		g_TempColor = g_ConsoleColor;

		g_TempColor = (g_TempColor & 0xF0) | (g_TempForegroundColor & 0x0F);
 		g_TempColor = (g_TempColor & 0x0F) | ((g_TempBackgroundColor & 0x0F) << 4);

		// The colour is also in the range 0-255,
		// as it is a pair of 4-bit colours.
		g_ConsoleBuffer[x + WIDTH * y].Attributes =  g_TempColor;
	}
	else
	{
		// The colour is also in the range 0-255,
		// as it is a pair of 4-bit colours.
		g_ConsoleBuffer[x + WIDTH * y].Attributes =  g_TempColor;
	}
}

//Viết 1 chuỗi lên buffer CHAR_INFO
void GPutStringToBuffer(char str[], int x, int y,  GColors foregroundColor, GColors backgroundColor)
{
	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		GPutCharToBuffer(str[i], i + x, y, foregroundColor, backgroundColor);
	}
}

//Flush all buffer CHAR_INFO to screen
void GFlushBuffer()
{
	// Set up the positions:
	COORD charBufSize = {WIDTH, HEIGH};
	COORD characterPos = {0, 0};
	SMALL_RECT writeArea = {0, 0, WIDTH - 1, HEIGH - 1}; 

	// Write the characters:
	WriteConsoleOutputA(hConsole, g_ConsoleBuffer, charBufSize, characterPos, &writeArea);
}
#endif //__UTILS_H__
