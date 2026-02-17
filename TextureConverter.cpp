#include "TextureConverter.h"
#include <windows.h>

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	//１.テクスチャファイルを読み込む
	LoadWICTextureFromFile(filePath);
	//２.DDS形式に変換して書き出す
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//テクスチャファイル読み込み
	//1.ファイルパスをワイド文字列に変換
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
	//2.テクスチャを読み込む
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//1.ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//2.ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//3.ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}