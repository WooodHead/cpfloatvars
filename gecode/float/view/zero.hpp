/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Yves Jaradin      <yves.jaradin@uclouvain.be>
 *     Gustavo Gutierrez <gutierrez.gustavo@uclouvain.be>
 *     Gonzalo Hernandez <gonzalohernandez@udenar.edu.co>
 *
 *  Copyright:
 *     Yves Jaradin, 2009
 *     Gustavo Gutierrez, 2009
 *     Gonzalo Hernandez, 2010
 *
 *  Last modified:
 *     $Date$ by $Author$
 *     $Revision$
 *
 *  This file is part of CP(Graph), a constraint system on graph veriables for
 *  Gecode: http://www.gecode.org  
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

namespace Gecode { 
  namespace Float {
  
    /*
     * Constructors and access
     *
     */
    
    forceinline
    ZeroView::ZeroView(void) {}
    

    /*
     * Cloning
     *
     */
  
    forceinline void
    ZeroView::update(Space* home, bool share, ZeroView& y) {}

    /*
     * Variable information
     *
     */
    
    forceinline bool
    ZeroView::assigned(void) const {
      return true;
    }
    
    /*
     * Domain update by value
     *
     */

    forceinline ModEvent
    ZeroView::lq(Space* home,double n) {
      return (0 <= n) ? ME_FLOAT_NONE : ME_FLOAT_FAILED;
    }

    forceinline ModEvent
    ZeroView::le(Space* home,double n) {
      return (0 < n) ? ME_FLOAT_NONE : ME_FLOAT_FAILED;
    }

    forceinline ModEvent
    ZeroView::gq(Space* home,double n) {
      return (0 >= n) ? ME_FLOAT_NONE : ME_FLOAT_FAILED;
    }

    forceinline ModEvent
    ZeroView::gr(Space* home,double n) {
      return (0 > n) ? ME_FLOAT_NONE : ME_FLOAT_FAILED;
    }

    /*
     * Value access
     *
     */

    forceinline double
    ZeroView::min(void) const {
      return 0;
    }

    forceinline double
    ZeroView::max(void) const {
      return 0;
    }

    forceinline double
    ZeroView::med(void) const {
      return 0;
    }

    /*
     * Dependencies
     *
     */

    forceinline void
    ZeroView::subscribe(Space* home, Propagator* p, PropCond pc, bool process) {}

    forceinline void
    ZeroView::cancel(Space* home, Propagator* p, PropCond pc) {}

  }
}
