.. _add_libraries_ar:

1.4 Bibliotheken installieren (Wichtig)
==========================================

Eine Bibliothek ist eine Sammlung von vorab geschriebenem Code oder Funktionen, die die Möglichkeiten der Arduino-IDE erweitern. Bibliotheken stellen fertigen Code für verschiedene Funktionen bereit und ermöglichen es Ihnen, Zeit und Mühe bei der Programmierung komplexer Features zu sparen.

Es gibt zwei Hauptmethoden, um Bibliotheken zu installieren:

Installation über die Bibliotheksverwaltung
--------------------------------------------

Viele Bibliotheken können direkt über die Arduino-Bibliotheksverwaltung installiert werden. Sie können die Bibliotheksverwaltung über die folgenden Schritte aufrufen:

#. In der **Library Manager** können Sie nach der gewünschten Bibliothek suchen oder verschiedene Kategorien durchsuchen.

   .. note::

      Bei Projekten, bei denen eine Bibliotheksinstallation erforderlich ist, gibt es Hinweise, welche Bibliotheken installiert werden müssen. Befolgen Sie die bereitgestellten Anweisungen wie z. B. "Die DHT-Sensorbibliothek wird hier verwendet. Sie können sie über die Bibliotheksverwaltung installieren." Installieren Sie einfach die empfohlenen Bibliotheken entsprechend den Hinweisen.

   .. image:: img/install_lib3.png

#. Sobald Sie die Bibliothek, die Sie installieren möchten, gefunden haben, klicken Sie darauf und anschließend auf die Schaltfläche **Install**.

   .. image:: img/install_lib2.png

#. Die Arduino-IDE wird die Bibliothek automatisch für Sie herunterladen und installieren.

.. _install_lib_man:

Manuelle Installation
--------------------------

Einige Bibliotheken sind nicht über die **Library Manager** verfügbar und müssen manuell installiert werden. Befolgen Sie diese Schritte, um diese Bibliotheken zu installieren:


#. Öffnen Sie die Arduino-IDE und gehen Sie zu **Sketch** -> **Include Library** -> **Add .ZIP Library**.

   .. image:: img/a2dp_add_zip.png

#. Navigieren Sie zum Verzeichnis, in dem sich die Bibliotheksdateien befinden, z. B. zum Ordner ``esp32-starter-kit\c\libraries``, und wählen Sie die gewünschte Bibliotheksdatei, z. B. ``ESP32-A2DP.zip``, aus. Klicken Sie dann auf **Open**.

   .. image:: img/a2dp_choose.png

#. Nach kurzer Zeit erhalten Sie eine Benachrichtigung über eine erfolgreiche Installation.

   .. image:: img/a2dp_success.png

#. Wiederholen Sie den gleichen Vorgang, um die Bibliothek ``ESP8266Audio.zip`` hinzuzufügen.


.. note::

   Die über eine der oben genannten Methoden installierten Bibliotheken finden Sie im Standardbibliotheksverzeichnis der Arduino-IDE, das sich normalerweise unter ``C:\Users\xxx\Documents\Arduino\libraries`` befindet.

   Wenn sich Ihr Bibliotheksverzeichnis an einem anderen Ort befindet, können Sie es über **File** -> **Preferences** überprüfen.

      .. image:: img/install_lib1.png