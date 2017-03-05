/*
Tag2Sub2.h
Signature Creation Time

Copyright (c) 2013 - 2017 Jason Lee @ calccrypto at gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef __TAG2_SUB2__
#define __TAG2_SUB2__

#include "../time.h"
#include "Tag2Subpacket.h"

// 5.2.3.4. Signature Creation Time
//
//    (4-octet time field)
//
//    The time the signature was made.
//
//    MUST be present in the hashed area.

class Tag2Sub2 : public Tag2Subpacket{
    private:
        time_t time;

    public:
        typedef std::shared_ptr <Tag2Sub2> Ptr;

        Tag2Sub2();
        Tag2Sub2(const std::string & data);
        void read(const std::string & data);
        std::string show(const uint8_t indents = 0, const uint8_t indent_size = 4) const;
        std::string raw() const;

        time_t get_time() const;

        void set_time(const time_t t);

        Tag2Subpacket::Ptr clone() const;
};

#endif
