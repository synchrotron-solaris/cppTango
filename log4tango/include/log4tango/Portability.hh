//
// Portability.hh
//
// Copyright (C) :  2000 - 2002
//					LifeLine Networks BV (www.lifeline.nl). All rights reserved.
//					Bastiaan Bakker. All rights reserved.   
//					
//					2004,2005,2006,2007,2008,2009,2010,2011,2012
//					Synchrotron SOLEIL
//                	L'Orme des Merisiers
//                	Saint-Aubin - BP 48 - France
//
// This file is part of log4tango.
//
// Log4ango is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Log4tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with Log4Tango.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _LOG4TANGO_PORTABILITY_H
#define _LOG4TANGO_PORTABILITY_H

#if defined (_MSC_VER) || defined(__BORLANDC__)
# include <log4tango/config-win32.h>
#else
# include <log4tango/config.h>
#endif

#include <log4tango/Export.hh>

#if defined(_MSC_VER)
# pragma warning( disable : 4786 ) // 255 char debug symbol limit
# pragma warning( disable : 4290 ) // throw specifier not implemented
# pragma warning( disable : 4251 ) // "class XXX should be exported"

#define LOG4TANGO_UNUSED(var) var
#else
	#ifdef __GNUC__
		#define LOG4TANGO_UNUSED(var) var __attribute__ ((unused))
	#else
		#define LOG4TANGO_UNUSED(var) var
	#endif
#endif

#ifndef LOG4TANGO_HAVE_SSTREAM
#include <strstream>
namespace std {
  class LOG4TANGO_EXPORT ostringstream : public ostrstream {
    public:
      std::string str();
      void str (const char*);
  };
}
#endif // LOG4TANGO_HAVE_SSTREAM

#endif // _LOG4TANGO_PORTABILITY_H
