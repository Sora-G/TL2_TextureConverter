#pragma once
#include"Externals/DirectXTex/DirectXTex.h"
#include <string>
class TextureConverter
{
public:
	//変換
	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	//テクスチャファイルの読み込み
	void LoadWICTextureFromFile(const std::string& filePath);

	//ワイド文字列への変換
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);
};