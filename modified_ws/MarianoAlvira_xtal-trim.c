/*
 * Copyright (c) 2010, Mariano Alvira <mar@devl.org> and other contributors
 * to the MC1322x project (http://mc1322x.devl.org)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of libmc1322x: see http://mc1322x.devl.org
 * for details.
 *
 *
 */
#include <mc1322x.h>
#include <board.h>
#include <stdio.h>
#include "config.h"
#include "tests.h"
int main(void)
{
    uint8_t ctune_4pf, ctune, ftune;
    ctune_4pf = 0;
    ctune = 0;
    ftune = 0;

    uart_init(UART1, 115200);

    print_welcome("pwm test\r\n");
    pack_XTAL_CNTL(ctune_4pf, ctune, ftune, IBIAS);
    for (;;) {
	switch (uart1_getc()) {
	case '[':
	    if (ctune > 0)
		ctune -= 1;
	    break;
	case ']':
	    if (ctune < 15)
		ctune += 1;
	    break;
	case '-':
	    if (ftune > 0)
		ftune -= 1;
	    break;
	case '=':
	    if (ftune < 31)
		ftune += 1;
	    break;
	case ' ':
	    if (ctune_4pf) {
		ctune_4pf = 0;
	    } else {
		ctune_4pf = 1;
	    }
	    break;
	}
	printf("ctune_4pf %d; ctune %d; ftune %d\n\r", ctune_4pf, ctune,
	       ftune);
	pack_XTAL_CNTL(ctune_4pf, ctune, ftune, IBIAS);
    }
}
