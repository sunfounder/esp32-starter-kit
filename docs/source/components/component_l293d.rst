.. _cpn_l293d:

L293D 
=================

L293Dは、高電圧および高電流で統合された4チャンネルのモータードライバです。
標準のDTL、TTL論理レベルに接続し、インダクティブロード（リレーコイル、DC、ステッピングモーターなど）や電力スイッチングトランジスタを駆動するために設計されています。
DCモーターは、DC電力を機械的エネルギーに変えるデバイスです。優れた速度調整性能のため、電気駆動に広く使用されています。

以下はピンの図です。L293Dには電源供給のための2つのピン（Vcc1とVcc2）があります。
Vcc2はモーターの電源供給に、Vcc1はチップの電源供給に使用されます。ここで小型のDCモーターが使用されているので、両方のピンを+5Vに接続します。

.. image:: img/l293d111.png

次に、L293Dの内部構造です。
ピンENは有効ピンで、高レベルでのみ動作します。Aは入力、Yは出力を示します。
右下にそれらの関係を確認できます。
ピンENがHighレベルの場合、AがHighの場合、Yは高レベルを出力します。AがLowの場合、YはLowレベルを出力します。ピンENがLowレベルの場合、L293Dは動作しません。

.. image:: img/l293d334.png

* `L293D Datasheet <https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1627004062301&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D>`_

**例**

* :ref:`ar_motor` (Arduinoプロジェクト)
* :ref:`ar_pump` (Arduinoプロジェクト)
* :ref:`py_motor` (MicroPythonプロジェクト)
* :ref:`py_pump` (MicroPythonプロジェクト)
* :ref:`sh_rotating_fan` (Scratchプロジェクト)
