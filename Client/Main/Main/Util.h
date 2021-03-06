#ifndef UTIL_H
#define UTIL_H

#pragma once

#include <algorithm>

void SetByte(DWORD offset,BYTE value);
void SetByteUnsafe(DWORD offset,BYTE value);
void SetWord(DWORD offset,WORD value);
void SetDword(DWORD offset,DWORD value);
void SetFloat(DWORD offset,float value);
void SetDouble(DWORD offset,double value);
void SetCompleteHook(BYTE head,DWORD offset,...);
void SetCompleteHookUnsafe(BYTE head,DWORD offset,...);
void MemoryCpy(DWORD offset,void* value,DWORD size);
void MemorySet(DWORD offset,DWORD value,DWORD size);
LPVOID HookFunction(const LPVOID offset, LPVOID function, DWORD size);
void PacketArgumentEncrypt(char* out_buff,char* in_buff,int size);

namespace std
{
	template <typename T>
	inline std::string to_string(T value)
	{
		std::ostringstream os ;
		os << value ;
		return os.str() ;
	}
}

class Xor
{
	public:
		static void BMD(BYTE * info, int Size);
		static void Byte3(char * info, int Size);
		static void LangXor(char * info, int Size, WORD key);
		static int Byte16(char * Source, char * Dest, int size);
		static void Byte20(char * src, char * dst, int size);
		static void ByteCustom(char * data, size_t size);

		static int Byte16New(char * Source, char * Dest, int size);

	private:
		static const DWORD KEY_SIZE_1					= 3;
		static const DWORD KEY_SIZE_2					= 16;
		static const DWORD KEY_SIZE_3					= 20;
		static const DWORD KEY_SIZE_CUSTOM				= 5;
};

//template<typename T>
//size_t FindString( const T& str1, const T& str2, const std::locale& loc = std::locale() )
//{
//    T::const_iterator it = std::search( str1.begin(), str1.end(), 
//        str2.begin(), str2.end(), my_equal<T::value_type>(loc) );
//    if ( it != str1.end() ) return it - str1.begin();
//    else return -1; // not found
//}
//
//inline void strToLower(std::string& str)
//{
//    std::transform(str.begin(), str.end(), str.begin(), tolower);
//}
//
//void ReplaceString(std::string &src, std::string const& search, std::string const& replace);

#endif