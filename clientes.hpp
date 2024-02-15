#ifndef CLIENTES_HPP
#define CLIENTES_HPP
#include <string>


/**
 * Clase encargada del registro de un nuevo usuario. Esta clase extrae el ID y su nombre del cliente y lo almacena en un archivo txt.
 * 
 * @license 
 * Copyright 2024 [Brenda Natalia Castro Jiménez, Emanuel Avilés Ramírez, Luis José Brenes Campos]
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */
class Clientes {

private:
    long long int cliente_id;
    std::string nombre;

public:


    Clientes(long long int id, const std::string& nombre); 

    void GuardarInformacion() const; // Esta funcion guarda los datos en un archivo llamado txt.  
};

#endif