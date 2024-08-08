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

