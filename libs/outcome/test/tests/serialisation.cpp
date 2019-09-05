/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "../../include/boost/outcome/iostream_support.hpp"
#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_monitor.hpp>

BOOST_OUTCOME_AUTO_TEST_CASE(works_outcome_serialisation, "Tests that the outcome serialises and deserialises as intended")
{
#if !defined(__APPLE__) || defined(__cpp_exceptions)
  using namespace BOOST_OUTCOME_V2_NAMESPACE;
  outcome<std::string> a("niall"), b(boost::system::error_code(5, boost::system::generic_category())), c(boost::copy_exception(std::ios_base::failure("A test failure message")));
  std::cout << "a contains " << print(a) << " and b contains " << print(b) << " and c contains " << print(c) << std::endl;

  std::stringstream ss;
  outcome<int, std::string, long> d(success(5));
  ss << d;
  ss.seekg(0);
  outcome<int, std::string, long> e(failure(""));
  ss >> e;
  BOOST_CHECK(d == e);
#endif
}
