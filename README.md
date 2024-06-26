# ML_Brushless_RL78G14

RL78/G14で、ブラシレスモーターを制御するサンプルです。  

詳しい解説はAPS-WEB様に掲載頂いています。  

このREADMEは補足説明です。

# 環境
IDE：[Renesas e² studio](https://www.renesas.com/jp/ja/software-tool/e-studio) Version: 2023-04 (23.4.0)

MCU：[RL78/G14](https://www.renesas.com/jp/ja/products/microcontrollers-microprocessors/rl78-low-power-8-16-bit-mcus/rl78g14-low-power-high-function-general-purpose-microcontrollers-motor-control-industrial-and-metering)

ボード：[RL78/G14 Fast Prototyping Board](https://www.renesas.com/jp/ja/products/microcontrollers-microprocessors/rl78-low-power-8-16-bit-mcus/rtk5rlg140c00000bj-rl78g14-fast-prototyping-board-rl78g14-fpb)


# 接続図
![接続図_RL78](https://github.com/miha-labs/ML_Brushless_RL78G14/assets/95220539/9bf6f296-9118-4a55-b5dd-25d7cd33d3d2)


# PC用アプリ
"ML_monitor.exe"  

![画面説明](https://github.com/miha-labs/ML_Brushless_STM32F030/assets/95220539/0ff92693-8873-4435-ad91-1a29c4921e47)  

(1) COMポートの選択とOpen/Close。MCUボードのVCPを選択する。

(2) 回転速度のモニタリングStart/Stop。モーターを手で回しても回転数モニターが可能。

(3) モーター駆動ON/OFFと回転速度指示。駆動をONにしてから回転速度を上げても良いし、回転速度を決めてから駆動をONにしても良い。

(4) 回転速度指示を±100[rpm]ずつ上下する。"0"ボタンで回転速度指示が0[rpm]となる。

(5) 回転速度指示のスライダ。スライダで回転速度指示を行っても良い。大体右のグラフのSpeed[rpm]と同じスケール。

(6) グラフの青線スケール(回転速度)。

(7) グラフの赤線スケール(電流)。


- グラフ表示について  
[ScottPlot](https://scottplot.net/)を使用させて頂きました。  
VisualStudio標準のプロッタより軽量で使いやすいのでおススメです。

# 免責事項
- このサンプルプログラムは[MITライセンス](https://github.com/miha-labs/ML_Brushless_RL78G14/blob/main/LICENSE)に従います。  
- [ScottPlot](https://github.com/ScottPlot/ScottPlot/blob/main/LICENSE)：Copyright (c) 2018 Scott Harden / Harden Technologies, LLC
- [Parts Copyright](http://www.renesas.com/disclaimer)： (C) 2010-2023 Renesas Electronics Corp. All rights reserved.

