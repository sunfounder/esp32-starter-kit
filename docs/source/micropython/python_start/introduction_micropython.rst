1.1 MicroPythonの紹介
======================================

MicroPythonは、C言語で書かれたPython 3と広く互換性のあるプログラミング言語のソフトウェア実装であり、マイクロコントローラ上で動作するように最適化されています。[3][4]

MicroPythonはバイトコードへのPythonコンパイラと、そのバイトコードのランタイムインタプリターから構成されています。ユーザーには、対応するコマンドを即座に実行できるインタラクティブプロンプト（REPL）が提供されます。Pythonのコアライブラリの選択が含まれており、MicroPythonにはプログラマーが低レベルハードウェアにアクセスできるモジュールが含まれています。

* 参照: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_

物語はここから始まります
--------------------------------

2013年、Damien Georgeがクラウドファンディングキャンペーン（Kickstarter）を開始した時に、事態は変わりました。

Damienはケンブリッジ大学の学部生であり、熱心なロボティクスプログラマーでした。彼はPythonの世界をギガバイト級のマシンからキロバイト級に縮小したいと考えていました。彼のKickstarterキャンペーンは、彼のコンセプトの証明を完成した実装に変えるための開発をサポートするものでした。

MicroPythonは、プロジェクトの成功に熱心な多様なPythonistaコミュニティによって支えられています。

コードベースのテストとサポートのみならず、開発者たちはチュートリアル、コードライブラリ、ハードウェアのポーティングを提供し、Damienはプロジェクトの他の側面に集中することができました。

* 参照: `realpython <https://realpython.com/micropython/>`_

なぜMicroPythonなのか？
--------------------------

元のKickstarterキャンペーンではSTM32F4を搭載した開発ボード「pyboard」としてMicroPythonがリリースされましたが、MicroPythonは多くのARMベースの製品アーキテクチャをサポートしています。メインラインでサポートされているポートには、ARM Cortex-M（多くのSTM32ボード、TI CC3200/WiPy、Teensyボード、Nordic nRFシリーズ、SAMD21およびSAMD51）、ESP8266、ESP32、16ビットPIC、Unix、Windows、Zephyr、JavaScriptがあります。
また、MicroPythonは迅速なフィードバックを可能にします。これは、REPLを使用してコマンドを対話的に入力し、応答を得ることができるためです。コードを微調整して即座に実行することもできるため、コード-コンパイル-アップロード-実行のサイクルを経る必要がありません。

Pythonも同様の利点がありますが、ESP32のようないくつかのマイクロコントローラボードにとって、それらは小さくシンプルで、Python言語を全て実行するにはメモリが少なすぎます。そのため、MicroPythonは主要なPythonの特徴を保ちつつ、これらのマイクロコントローラボードで動作するための新しい機能を追加して進化しています。

次に、ESP32にMicroPythonをインストールする方法を学びます。

* 参照: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_
* 参照: `realpython <https://realpython.com/micropython/>`_
