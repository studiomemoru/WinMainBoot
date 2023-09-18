#pragma once
/**
 * @file configure.hpp
 * WinMainBoot
 * アプリケーションの設定を記述します。
 */
/*
   Copyright (c) 2022, YOSHIMURA Takanori, studio memoru

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

//! リソース(rc)を利用するかどうか。利用する場合は 1 、利用しない場合は 0 にする。
#define WMB_USE_RESOURCES           (0)

//! メインウィンドウのウィンドウクラス名
#define WMB_WINDOW_CLASSNAME		L"WinMainBoot"

//! メインウィンドウのタイトル文字列
#define WMB_TITLE					L"Main Window"

#if WMB_USE_RESOURCES

//! アクセラレータテーブルのリソース識別子
#define WMB_RES_ACCELERATORS		L"WinMainBoot"

#endif
