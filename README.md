# Diseño de un pulsómetro por infrarrojos

Trabajo Fin de Grado consistente en diseñar un pulsómetro basado en pleistomografía con sensor infrarrojo.

## Estructura del repositorio

* `circuitos/`  Archivos CAD y CAM del proyecto
  - `circuitos/eagle/`  Esquema del circuito y diseño de la PCB, usando *Eagle*
  - `circuitos/kicad/`  Esquema del circuito auxiliar para programar el firmware durante la fase de prototipo, usando *KiCad*
  - `circuitos/spice/`  Esquemas de los filtros, usando *gschem*, y *netlist* para simulación con *ngspice*
* `data/`        Resultados en bruto de pruebas de validación y resultados de simulaciones
* `datasheets/`  Hojas de características
* `img/`         Imágenes usadas en la memoria
* `presentacion/` Presentación de la defensa
  - `presentacion/video/` Vídeo de demostración
* `report/`     Memoria del Trabajo Fin de Grado, fuentes para construirla y bibliografía
* `src/`        Código fuente
  - `src/Pulsometro`    Fuentes de la aplicación Pulsómetro para Android, usando Android Studio
  - `src/androidplot`   Referencia, `git submodule`, a las fuentes de la biblioteca *androidplot*.
  - `src/pulsometro.X`  Fuentes del firmware para el micocontrolador, usando MPLAB X

## Licencias/Licensing

 * circuitos/
 ``` 
    Copyright (C) 2015 Rafael Bailón-Ruiz
    
    This documentation describes Open Hardware and is licensed under the
    CERN OHL v. 1.2.
    
    You may redistribute and modify this documentation under the terms of the
    CERN OHL v.1.2. (http://ohwr.org/cernohl). This documentation is
    distributed WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF
    MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A PARTICULAR PURPOSE.
    Please see the CERN OHL v.1.2 for applicable conditions.
 ```
 
 * data/
 ```
    Copyright (C) 2015  Rafael Bailón-Ruiz
    
    This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
    International License. To view a copy of this license, visit 
    http://creativecommons.org/licenses/by-sa/4.0/.
 ```
 
 * img/
 ```
    Images with bibliography citation (/report/bibliography.bib) are property
    of their respective authors. Otherwise, images are own-work or come from
    public domain and the following copyright notice applies:
    
    Copyright (C) 2015  Rafael Bailón-Ruiz
    
    This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
    International License. To view a copy of this license, visit 
    http://creativecommons.org/licenses/by-sa/4.0/.
 ```
 
 * presentacion/ & report/
 ```
    Copyright (C) 2015  Rafael Bailón-Ruiz
    
    This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
    International License. To view a copy of this license, visit 
    http://creativecommons.org/licenses/by-sa/4.0/.
 ```
 
 * src/
 ```
    Pulsómetro
    Copyright (C) 2015  Rafael Bailón-Ruiz
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ```
