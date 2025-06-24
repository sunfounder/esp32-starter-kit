.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _install_driver:

Instalación manual del controlador para ESP32
==============================================

Si has conectado tu placa ESP32 al ordenador mediante USB pero **no ves ningún puerto** en Arduino IDE o Thonny IDE (o solo aparece **COM1**), es que tu ordenador no reconoce la placa.  
En este caso, deberás instalar manualmente el controlador USB.

Ofrecemos dos versiones de placas ESP32, que solo se diferencian por el chip USB‑serie que usan:

- **CP2102**
- **CH340**

Funcionalmente son iguales; la única diferencia es el controlador USB requerido.

.. image:: img/driver_ch340_cp2102.jpg
   :width: 400
   :align: center

* Si tu placa ESP32 utiliza el chip USB **CH340**, sigue esta guía para instalar el controlador:

  * :ref:`driver_ch340`

* Si tu placa ESP32 utiliza el chip USB **CP2102**, sigue en su lugar esta guía:

  * :ref:`driver_cp2102`


.. _driver_ch340:

Cómo instalar el controlador CH340
-----------------------------------

En este tutorial te explicamos cómo instalar el controlador CH340 en diferentes sistemas operativos. En muchos casos, el sistema lo instala automáticamente. Sin embargo, según tu versión o configuración, puede que necesites instalarlo manualmente la primera vez que conectes un dispositivo CH340.

Controladores
^^^^^^^^^^^^^

El chip CH340 es de WCH. Aquí tienes los enlaces oficiales desde su web:

* `Windows (ZIP) <https://www.wch.cn/download/file?id=5>`_ – controlador v3.4 (16‑10‑2024)  
* `Windows (EXE) <https://www.wch.cn/download/file?id=65>`_ – instalador ejecutable  
* `Mac (ZIP) <https://www.wch.cn/download/file?id=178>`_ – controlador v1.5 (26‑02‑2025)  
* `Linux (ZIP) <https://www.wch.cn/download/file?id=177>`_ – controlador v1.5 (24‑10‑2024)

También puedes visitar la web oficial de WCH para descargar la versión más reciente. Actualmente está disponible en esta página en chino:

* `Descarga de controladores WCH <https://www.wch.cn/downloads/CH343SER_EXE.html>`_

Si usas Chrome, puedes traducir automáticamente la página.

A continuación, explicamos cómo instalar el controlador CH340 en cada sistema.

Windows 7/11
^^^^^^^^^^^^^

#. Descarga el controlador:

   * `Windows (ZIP) <https://www.wch.cn/download/file?id=5>`_ – v3.4 (16‑10‑2024)  
   * `Windows (EXE) <https://www.wch.cn/download/file?id=65>`_ – instalador

#. Haz doble clic en el archivo ``.exe``. Si descargaste el ZIP, extráelo y ejecuta el ``.exe`` dentro.

#. Pulsa **Desinstalar** para eliminar posibles controladores anteriores y luego **Instalar**.

   .. image:: img/driver_ch340_install.png

#. Tras la instalación, abre el **Administrador de dispositivos** (presiona ⊞ Win + R, escribe ``devmgmt.msc`` y pulsa Enter).

   .. image:: img/driver_ch340_device.png

#. En "Puertos (COM & LPT)", debería aparecer **USB‑SERIAL CH340 (COM##)**. El número COM puede variar.

   .. image:: img/driver_ch340_com.png

macOS
^^^^^^

#. Descarga y descomprime el paquete:

   * `Mac (ZIP) <https://www.wch.cn/download/file?id=178>`_ – v1.5 (26‑02‑2025)

#. Abre la carpeta y haz doble clic en el archivo ``.pkg`` para iniciar la instalación.

   .. note::

      En macOS 10.13 o superior puede bloquearse la extensión.  
      Si ocurre, ve a **Ajustes del sistema > Privacidad y seguridad** y haz clic en **Permitir** junto a la extensión bloqueada.  
      Quizá necesites desbloquear (icono de candado + contraseña) y reiniciar el Mac.

   .. image:: img/driver_ch340_install_mac.png
      :width: 500
      :align: center

#. Para comprobarlo, conecta el dispositivo CH340 y abre Terminal:

   .. code-block::

      ls /dev/cu*

#. Deberías ver algo como ``/dev/cu.usbserial*****`` (el nombre exacto puede variar).

   .. image:: img/driver_ch340_mac_port.png
      :width: 500
      :align: center

Linux
^^^^^^

#. La mayoría de distribuciones Linux ya incluyen el controlador CH340. Bastará con conectar el dispositivo.

#. Si no se detecta, actualiza el sistema:

   .. code-block::

      sudo apt-get update
      sudo apt-get upgrade

#. Para instalar manualmente, descarga:

   * `Linux (ZIP) <https://www.wch.cn/download/file?id=177>`_ – v1.5 (24‑10‑2024)

#. Vuelve a conectar y ejecuta:

   .. code-block::

      ls /dev/ttyUSB*

#. Deberías ver algo como:

   .. code-block::

      /dev/ttyUSB0


.. _driver_cp2102:

¿Cómo instalar el controlador CH2102?
--------------------------------------

Esta guía te mostrará cómo instalar el controlador USB a serie CH2102 en diferentes sistemas operativos.  
En muchos casos, el sistema operativo lo instala automáticamente. Sin embargo, dependiendo de la versión o configuración del sistema, puede ser necesario instalar el controlador manualmente la primera vez que conectes un dispositivo CH2102 a tu ordenador.

Windows
^^^^^^^^^^^^^

#. Visita la página `Silicon Labs USB to UART Bridge VCP Drivers <https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads>`_ y descarga el archivo **CP210x_Universal_Windows_Driver**.

#. Extrae el archivo ZIP, luego haz clic derecho en el archivo ``.inf`` y selecciona **Instalar**. Sigue las instrucciones en pantalla para completar la instalación.

   .. image:: img/driver_cp2102_install.png

#. Una vez instalado, conecta el dispositivo CP2102 a un puerto USB. Abre el **Administrador de dispositivos** (presiona ⊞ Win + R, escribe ``devmgmt.msc`` y presiona Enter).

#. Expande la sección **Puertos (COM & LPT)**. Deberías ver una entrada como: ``Silicon Labs CP210x USB to UART Bridge (COM#)``.

   .. image:: img/driver_cp2102_com.png

#. Si el dispositivo aparece sin ningún icono de advertencia, el controlador se ha instalado correctamente y está funcionando.

macOS
^^^^^^^^^^^^^

El puente USB a UART CP2102 es fabricado por Silicon Labs. En versiones recientes de macOS, el sistema puede incluir soporte básico, pero se recomienda instalar el controlador oficial de Silicon Labs para una mejor compatibilidad y estabilidad.

#. Visita la página `USB to UART Bridge VCP Drivers <https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads>`_ y descarga el **CP210x VCP Mac OSX Driver** correspondiente a tu sistema (Apple Silicon o Intel).

#. Extrae el archivo ZIP descargado y haz doble clic en el archivo ``.dmg`` para montarlo.

#. En el volumen montado, abre y ejecuta **Install CP210x VCP Driver.app**.

#. Sigue las instrucciones en pantalla para completar la instalación.

   .. image:: img/driver_cp2102_mac_install.png
      :width: 500

#. En macOS 10.13 o posterior, el sistema puede bloquear la extensión del controlador. Si se te solicita:

   * Ve a **Configuración del sistema > Privacidad y seguridad**
   * Haz clic en **Permitir** junto a la extensión de Silicon Labs
   * Desbloquea la configuración si es necesario (haz clic en el candado e ingresa tu contraseña)
   * Reinicia tu Mac para aplicar los cambios

#. Después de la instalación, **reinicia tu Mac** si aún no lo has hecho.

#. Para verificar que el controlador se haya instalado, abre la Terminal y ejecuta:

   .. code-block::

      ls /dev/cu.*

#. Deberías ver un dispositivo como el siguiente, lo que indica que el controlador está funcionando correctamente:

   .. code-block::

      /dev/cu.SLAB_USBtoUART

Linux
^^^^^^^^^^^^^

#. La mayoría de las distribuciones de Linux (por ejemplo, Ubuntu, Debian, Fedora) ya incluyen soporte para el controlador CP2102. En general, basta con conectar el dispositivo para que esté disponible automáticamente.

#. Si el dispositivo no se reconoce, intenta actualizar tu sistema:

   .. code-block::

      sudo apt-get update
      sudo apt-get upgrade

#. Después de actualizar, vuelve a conectar el dispositivo CP2102 y ejecuta el siguiente comando en una terminal:

   .. code-block::

      ls /dev/ttyUSB*

#. Si el controlador está funcionando correctamente, deberías ver un dispositivo como:

   .. code-block::

      /dev/ttyUSB0

#. También puedes revisar los registros del kernel para verificar la detección:

   .. code-block::

      dmesg | grep ttyUSB
