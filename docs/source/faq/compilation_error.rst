Certains codes de projet ne se compilent pas ?
===================================================

Q1 : ``'ledcAttach' was not declared in this scope``
--------------------------------------------------------

Lors de l'utilisation de LEDs, de LEDs RVB ou de buzzers passifs, vous aurez besoin du périphérique |link_ledc| de la carte ESP32 pour générer des signaux PWM. Cependant, la carte ESP32 a récemment été mise à jour vers la version 3.0, ce qui a entraîné des changements dans les noms et l'utilisation des fonctions au sein du périphérique |link_ledc|.

Par conséquent, nous avons mis à jour notre code en conséquence. Si vous rencontrez des problèmes liés à ledc lors de la compilation, veuillez mettre à niveau votre carte ESP32 vers la version 3.0 ou supérieure.

.. image:: img/version_3.0.3.png


Q2 : Erreurs dans les projets liés au Bluetooth et au récepteur IR après la mise à jour de l'ESP32 vers la version 3.0 ?
--------------------------------------------------------------------------------------------------------------------------

La carte ESP32 a été mise à jour vers la version 3.0, mais les bibliothèques utilisées dans les projets liés au Bluetooth et au récepteur IR ne sont pas encore compatibles avec la version 3.0.

Pour exécuter ces projets, il est recommandé de rétrograder temporairement la version de l'ESP32 à 2.0, en particulier la version 2.0.17.

Nous surveillerons continuellement les mises à jour de ces bibliothèques, et une fois qu'elles seront compatibles avec la version 3.0 de l'ESP32, nous mettrons rapidement à jour notre code et notre documentation.

.. image:: img/version_2.0.17.png

.. _download_mode:

Q3 : Erreur “Wrong boot mode detected (0x13)” lors du flashage du firmware ESP32
--------------------------------------------------------------------------------------

Lors du flashage du firmware ESP32 avec Thonny ou lors du téléchargement de code sur l’ESP32 via l’IDE Arduino, vous pouvez rencontrer l’erreur suivante :

.. code-block:: text

    A fatal error occurred: Failed to connect to ESP32: Wrong boot mode detected (0x13)! The chip needs to be in download mode.

Cela **n’indique pas** un problème matériel avec votre carte ESP32.  
Ce problème peut survenir lorsque l’ordinateur ne parvient pas à mettre automatiquement l’ESP32 en **mode téléchargement** pendant le processus de flashage.

**Cause**

L’ESP32 doit être en **mode téléchargement** pour flasher le firmware correctement.  
Dans certains environnements, le déclenchement automatique du mode téléchargement peut ne pas fonctionner comme prévu en raison de différences de synchronisation dans les pilotes USB, du comportement du port USB ou de la manière dont le système d’exploitation gère les signaux DTR/RTS.  
En conséquence, l’ESP32 reste en mode d’exécution normal, ce qui provoque l’échec du flashage.

**Solution**

Si vous rencontrez cette erreur, vous pouvez entrer manuellement en mode téléchargement avant le flashage :

* **En utilisant les boutons (BOOT + EN/RST)** :  
  Appuyez et maintenez le bouton ``BOOT``, appuyez brièvement sur ``EN`` (ou ``RST``), puis relâchez ``BOOT``.  
  Cela force l’ESP32 à entrer en mode téléchargement.

* **En utilisant un cavalier (jumper)** :  
  Reliez ``GPIO0`` à ``GND`` à l’aide d’un cavalier, puis appuyez sur ``EN`` (ou redémarrez la carte) pour passer en mode téléchargement.  
  Après le flashage, retirez le cavalier pour permettre un démarrage normal.

**Remarques**

* Assurez-vous d’utiliser un **câble de données** approprié (et non un simple câble de charge).  
* Si le problème persiste, essayez de changer de port USB, de mettre à jour le pilote USB-série ou de réduire le débit en bauds (par exemple ``115200``).
