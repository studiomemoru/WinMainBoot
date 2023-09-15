# WinMainBoot

Skeleton projects for Win32 applications.

Win32 アプリケーション用スケルトンプロジェクト。

## License

Apache License 2.0

## プロジェクト概要

Win32 アプリケーション作成の起点となる、必要最小限のプロジェクト・ソリューションを提供します。

- ひとまず日本語環境で動かすアプリのみを想定。
- 基本的に変更する事の無い WinMain （エントリーポイント ～ メインウィンドウ作成 ～ メッセージループ）のソースと、実装を作り込んでいくウィンドウプロシージャー以降を分離。
- ソースファイルのエンコードをUTF-8（BOMあり）に設定。
- Unicode APIのみを使う前提。"tchar.h" は使わない。
- ビジュアル スタイル（Windows XP 以降）対応。

## アプリケーションタイプ別構成

### [FrameWindow](FrameWindow/README.md)
メインウィンドウとしてフレームウィンドウを使用する。
リソースを使用しない。

