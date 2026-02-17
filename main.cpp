#include<cstdio>
#include<cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include <winerror.h>
#include <objbase.h>

//グローバル関数
enum Argument
{
    //コマンドライン引数
    kApplicationPath,//アプリケーションのパス
    kFilePath,//渡されたファイルのパス

    NumArgument
};

int main(int argc, char* argv[]) {

    //argcの数だけ繰り返す
    for (int i = 0; i < argc; i++) {
        //文字列argvのi番を表示
        printf(argv[i]);

        //改行
        printf("\n");
    }

    //system("pause");

    assert(argc >= NumArgument);

    //COMライブラリの初期化
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    assert(SUCCEEDED(hr));

    //1.テクスチャコンバータのインスタンス生成
    TextureConverter converter;

    //2.テクスチャ変換
    converter.ConvertTextureWICToDDS(argv[kFilePath]);

    //COMライブラリの終了
    CoUninitialize();

    return 0;
}