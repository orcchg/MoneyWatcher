/*
 * exception.h
 *
 *  Created on: 22.06.2013
 *      Author: dla
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_


namespace mw {
namespace exception {

class Exception {
public:
  Exception(const std::string& msg)
    : _msg(msg) {
  }

private:
  std::string _msg;
};

}  // namespace exception
}  // namespace mw


#endif /* EXCEPTION_H_ */
