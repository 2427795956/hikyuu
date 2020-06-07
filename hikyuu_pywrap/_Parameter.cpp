/*
 *  Copyright (c) 2019 hikyuu.org
 *
 *  Created on: 2020-5-24
 *      Author: fasiondog
 */

#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <hikyuu/utilities/Parameter.h>
#include "_Parameter.h"
#include "pickle_support.h"

using namespace hku;
namespace py = pybind11;

std::string Parameter_to_str(const Parameter& param) {
    std::stringstream ss;
    ss << param;
    return ss.str();
}

void export_Parameter(py::module& m) {
    py::class_<Parameter>(m, "Parameter")
      .def(py::init<>())
      .def("__str__", &Parameter_to_str)
      .def("__repr__", &Parameter_to_str)

      .def("have", &Parameter::have, "Return True if there is a parameter for the specified name.")

      .def("__setitem__", &Parameter::set<boost::any>)
      .def("__getitem__", &Parameter::get<boost::any>)
      .def("set", &Parameter::set<boost::any>)
      .def("get", &Parameter::get<boost::any>)
      .def("type", &Parameter::type,
           "Get the type name of the specified parameter, return 'string' | 'int' | 'double' | "
           "'bool' | 'Stock' | 'KQuery' | 'KData' | 'PriceList' | 'DatetimeList'")
      .def("get_name_list", &Parameter::getNameList, "Get all the parameter names list")
      .def("get_name_value_list", &Parameter::getNameValueList,
           "Return a string, like 'name1=val1,name2=val2,...'")

      .def(py::self == py::self)
      .def(py::self != py::self)
      .def(py::self < py::self)

        DEF_PICKLE(Parameter);
}