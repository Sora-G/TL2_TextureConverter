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

	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;

	//ファイルパスの分解
	void SeparateFilePath(const std::wstring& filePath);
	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;
	//テクスチャファイル書き出し
	void SaveDDSTextureToFile();
};