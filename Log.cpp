#include "Log.hpp"

Usuario* Log::getUsuario() {return this->usuario;}

Data Log::getData() {return this->data;}

std::string Log::getEntity() {return this->entidade;}

list<Log> Log::getListLog() {
  return listLog;
}

void Log::printTodosLogs() {

}