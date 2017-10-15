/* Test of <bitrotate.h> substitute.
   Copyright (C) 2007-2011 Free Software Foundation, Inc.
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
/* Written by Simon Josefsson <simon@josefsson.org>, 2008.  */
#include <config.h>
#include "bitrotate.h"
#include "macros.h"
int main(void)
{
    ASSERT(rotl8(42, 0) == 42);
    ASSERT(rotl8(42, 1) == 84);
    ASSERT(rotl8(42, 2) == 168);
    ASSERT(rotl8(42, 3) == 81);
    ASSERT(rotl8(42, 4) == 162);
    ASSERT(rotl8(42, 5) == 69);
    ASSERT(rotl8(42, 6) == 138);
    ASSERT(rotl8(42, 7) == 21);
    ASSERT(rotl8(42, 8) == 42);
    ASSERT(rotr8(42, 0) == 42);
    ASSERT(rotr8(42, 1) == 21);
    ASSERT(rotr8(42, 2) == 138);
    ASSERT(rotr8(42, 3) == 69);
    ASSERT(rotr8(42, 4) == 162);
    ASSERT(rotr8(42, 5) == 81);
    ASSERT(rotr8(42, 6) == 168);
    ASSERT(rotr8(42, 7) == 84);
    ASSERT(rotr8(42, 8) == 42);
    ASSERT(rotl16(43981, 0) == 43981);
    ASSERT(rotl16(43981, 1) == 22427);
    ASSERT(rotl16(43981, 2) == 44854);
    ASSERT(rotl16(43981, 3) == 24173);
    ASSERT(rotl16(43981, 4) == 48346);
    ASSERT(rotl16(43981, 5) == 31157);
    ASSERT(rotl16(43981, 6) == 62314);
    ASSERT(rotl16(43981, 7) == 59093);
    ASSERT(rotl16(43981, 8) == 52651);
    ASSERT(rotl16(43981, 9) == 39767);
    ASSERT(rotl16(43981, 10) == 13999);
    ASSERT(rotl16(43981, 11) == 27998);
    ASSERT(rotl16(43981, 12) == 55996);
    ASSERT(rotl16(43981, 13) == 46457);
    ASSERT(rotl16(43981, 14) == 27379);
    ASSERT(rotl16(43981, 15) == 54758);
    ASSERT(rotl16(43981, 16) == 43981);
    ASSERT(rotr16(43981, 0) == 43981);
    ASSERT(rotr16(43981, 1) == 54758);
    ASSERT(rotr16(43981, 2) == 27379);
    ASSERT(rotr16(43981, 3) == 46457);
    ASSERT(rotr16(43981, 4) == 55996);
    ASSERT(rotr16(43981, 5) == 27998);
    ASSERT(rotr16(43981, 6) == 13999);
    ASSERT(rotr16(43981, 7) == 39767);
    ASSERT(rotr16(43981, 8) == 52651);
    ASSERT(rotr16(43981, 9) == 59093);
    ASSERT(rotr16(43981, 10) == 62314);
    ASSERT(rotr16(43981, 11) == 31157);
    ASSERT(rotr16(43981, 12) == 48346);
    ASSERT(rotr16(43981, 13) == 24173);
    ASSERT(rotr16(43981, 14) == 44854);
    ASSERT(rotr16(43981, 15) == 22427);
    ASSERT(rotr16(43981, 16) == 43981);
    ASSERT(rotl32(2309737967U, 1) == 324508639U);
    ASSERT(rotl32(2309737967U, 2) == 649017278U);
    ASSERT(rotl32(2309737967U, 3) == 1298034556U);
    ASSERT(rotl32(2309737967U, 4) == 2596069112U);
    ASSERT(rotl32(2309737967U, 5) == 897170929U);
    ASSERT(rotl32(2309737967U, 6) == 1794341858U);
    ASSERT(rotl32(2309737967U, 7) == 3588683716U);
    ASSERT(rotl32(2309737967U, 8) == 2882400137U);
    ASSERT(rotl32(2309737967U, 9) == 1469832979U);
    ASSERT(rotl32(2309737967U, 10) == 2939665958U);
    ASSERT(rotl32(2309737967U, 11) == 1584364621U);
    ASSERT(rotl32(2309737967U, 12) == 3168729242U);
    ASSERT(rotl32(2309737967U, 13) == 2042491189U);
    ASSERT(rotl32(2309737967U, 14) == 4084982378U);
    ASSERT(rotl32(2309737967U, 15) == 3874997461U);
    ASSERT(rotl32(2309737967U, 16) == 3455027627U);
    ASSERT(rotl32(2309737967U, 17) == 2615087959U);
    ASSERT(rotl32(2309737967U, 18) == 935208623U);
    ASSERT(rotl32(2309737967U, 19) == 1870417246U);
    ASSERT(rotl32(2309737967U, 20) == 3740834492U);
    ASSERT(rotl32(2309737967U, 21) == 3186701689U);
    ASSERT(rotl32(2309737967U, 22) == 2078436083U);
    ASSERT(rotl32(2309737967U, 23) == 4156872166U);
    ASSERT(rotl32(2309737967U, 24) == 4018777037U);
    ASSERT(rotl32(2309737967U, 25) == 3742586779U);
    ASSERT(rotl32(2309737967U, 26) == 3190206263U);
    ASSERT(rotl32(2309737967U, 27) == 2085445231U);
    ASSERT(rotl32(2309737967U, 28) == 4170890462U);
    ASSERT(rotl32(2309737967U, 29) == 4046813629U);
    ASSERT(rotl32(2309737967U, 30) == 3798659963U);
    ASSERT(rotl32(2309737967U, 31) == 3302352631U);
    ASSERT(rotr32(2309737967U, 1) == 3302352631lU);
    ASSERT(rotr32(2309737967U, 2) == 3798659963lU);
    ASSERT(rotr32(2309737967U, 3) == 4046813629lU);
    ASSERT(rotr32(2309737967U, 4) == 4170890462lU);
    ASSERT(rotr32(2309737967U, 5) == 2085445231lU);
    ASSERT(rotr32(2309737967U, 6) == 3190206263lU);
    ASSERT(rotr32(2309737967U, 7) == 3742586779lU);
    ASSERT(rotr32(2309737967U, 8) == 4018777037lU);
    ASSERT(rotr32(2309737967U, 9) == 4156872166lU);
    ASSERT(rotr32(2309737967U, 10) == 2078436083lU);
    ASSERT(rotr32(2309737967U, 11) == 3186701689lU);
    ASSERT(rotr32(2309737967U, 12) == 3740834492lU);
    ASSERT(rotr32(2309737967U, 13) == 1870417246lU);
    ASSERT(rotr32(2309737967U, 14) == 935208623lU);
    ASSERT(rotr32(2309737967U, 15) == 2615087959lU);
    ASSERT(rotr32(2309737967U, 16) == 3455027627lU);
    ASSERT(rotr32(2309737967U, 17) == 3874997461lU);
    ASSERT(rotr32(2309737967U, 18) == 4084982378lU);
    ASSERT(rotr32(2309737967U, 19) == 2042491189lU);
    ASSERT(rotr32(2309737967U, 20) == 3168729242lU);
    ASSERT(rotr32(2309737967U, 21) == 1584364621lU);
    ASSERT(rotr32(2309737967U, 22) == 2939665958lU);
    ASSERT(rotr32(2309737967U, 23) == 1469832979lU);
    ASSERT(rotr32(2309737967U, 24) == 2882400137lU);
    ASSERT(rotr32(2309737967U, 25) == 3588683716lU);
    ASSERT(rotr32(2309737967U, 26) == 1794341858lU);
    ASSERT(rotr32(2309737967U, 27) == 897170929lU);
    ASSERT(rotr32(2309737967U, 28) == 2596069112lU);
    ASSERT(rotr32(2309737967U, 29) == 1298034556lU);
    ASSERT(rotr32(2309737967U, 30) == 649017278lU);
    ASSERT(rotr32(2309737967U, 31) == 324508639lU);
#ifdef UINT64_MAX
    ASSERT(rotl64(16045690984503098046ULL, 1) == 13644637895296644477ULL);
    ASSERT(rotl64(16045690984503098046ULL, 2) == 8842531716883737339ULL);
    ASSERT(rotl64(16045690984503098046ULL, 3) == 17685063433767474678ULL);
    ASSERT(rotl64(16045690984503098046ULL, 4) == 16923382793825397741ULL);
    ASSERT(rotl64(16045690984503098046ULL, 5) == 15400021513941243867ULL);
    ASSERT(rotl64(16045690984503098046ULL, 6) == 12353298954172936119ULL);
    ASSERT(rotl64(16045690984503098046ULL, 7) == 6259853834636320623ULL);
    ASSERT(rotl64(16045690984503098046ULL, 8) == 12519707669272641246ULL);
    ASSERT(rotl64(16045690984503098046ULL, 9) == 6592671264835730877ULL);
    ASSERT(rotl64(16045690984503098046ULL, 10) == 13185342529671461754ULL);
    ASSERT(rotl64(16045690984503098046ULL, 11) == 7923940985633371893ULL);
    ASSERT(rotl64(16045690984503098046ULL, 12) == 15847881971266743786ULL);
    ASSERT(rotl64(16045690984503098046ULL, 13) == 13249019868823935957ULL);
    ASSERT(rotl64(16045690984503098046ULL, 14) == 8051295663938320299ULL);
    ASSERT(rotl64(16045690984503098046ULL, 15) == 16102591327876640598ULL);
    ASSERT(rotl64(16045690984503098046ULL, 16) == 13758438582043729581ULL);
    ASSERT(rotl64(16045690984503098046ULL, 17) == 9070133090377907547ULL);
    ASSERT(rotl64(16045690984503098046ULL, 18) == 18140266180755815094ULL);
    ASSERT(rotl64(16045690984503098046ULL, 19) == 17833788287802078573ULL);
    ASSERT(rotl64(16045690984503098046ULL, 20) == 17220832501894605531ULL);
    ASSERT(rotl64(16045690984503098046ULL, 21) == 15994920930079659447ULL);
    ASSERT(rotl64(16045690984503098046ULL, 22) == 13543097786449767279ULL);
    ASSERT(rotl64(16045690984503098046ULL, 23) == 8639451499189982943ULL);
    ASSERT(rotl64(16045690984503098046ULL, 24) == 17278902998379965886ULL);
    ASSERT(rotl64(16045690984503098046ULL, 25) == 16111061923050380157ULL);
    ASSERT(rotl64(16045690984503098046ULL, 26) == 13775379772391208699ULL);
    ASSERT(rotl64(16045690984503098046ULL, 27) == 9104015471072865783ULL);
    ASSERT(rotl64(16045690984503098046ULL, 28) == 18208030942145731566ULL);
    ASSERT(rotl64(16045690984503098046ULL, 29) == 17969317810581911517ULL);
    ASSERT(rotl64(16045690984503098046ULL, 30) == 17491891547454271419ULL);
    ASSERT(rotl64(16045690984503098046ULL, 31) == 16537039021198991223ULL);
    ASSERT(rotl64(16045690984503098046ULL, 32) == 14627333968688430831ULL);
    ASSERT(rotl64(16045690984503098046ULL, 33) == 10807923863667310047ULL);
    ASSERT(rotl64(16045690984503098046ULL, 34) == 3169103653625068479ULL);
    ASSERT(rotl64(16045690984503098046ULL, 35) == 6338207307250136958ULL);
    ASSERT(rotl64(16045690984503098046ULL, 36) == 12676414614500273916ULL);
    ASSERT(rotl64(16045690984503098046ULL, 37) == 6906085155290996217ULL);
    ASSERT(rotl64(16045690984503098046ULL, 38) == 13812170310581992434ULL);
    ASSERT(rotl64(16045690984503098046ULL, 39) == 9177596547454433253ULL);
    ASSERT(rotl64(16045690984503098046ULL, 40) == 18355193094908866506ULL);
    ASSERT(rotl64(16045690984503098046ULL, 41) == 18263642116108181397ULL);
    ASSERT(rotl64(16045690984503098046ULL, 42) == 18080540158506811179ULL);
    ASSERT(rotl64(16045690984503098046ULL, 43) == 17714336243304070743ULL);
    ASSERT(rotl64(16045690984503098046ULL, 44) == 16981928412898589871ULL);
    ASSERT(rotl64(16045690984503098046ULL, 45) == 15517112752087628127ULL);
    ASSERT(rotl64(16045690984503098046ULL, 46) == 12587481430465704639ULL);
    ASSERT(rotl64(16045690984503098046ULL, 47) == 6728218787221857663ULL);
    ASSERT(rotl64(16045690984503098046ULL, 48) == 13456437574443715326ULL);
    ASSERT(rotl64(16045690984503098046ULL, 49) == 8466131075177879037ULL);
    ASSERT(rotl64(16045690984503098046ULL, 50) == 16932262150355758074ULL);
    ASSERT(rotl64(16045690984503098046ULL, 51) == 15417780227001964533ULL);
    ASSERT(rotl64(16045690984503098046ULL, 52) == 12388816380294377451ULL);
    ASSERT(rotl64(16045690984503098046ULL, 53) == 6330888686879203287ULL);
    ASSERT(rotl64(16045690984503098046ULL, 54) == 12661777373758406574ULL);
    ASSERT(rotl64(16045690984503098046ULL, 55) == 6876810673807261533ULL);
    ASSERT(rotl64(16045690984503098046ULL, 56) == 13753621347614523066ULL);
    ASSERT(rotl64(16045690984503098046ULL, 57) == 9060498621519494517ULL);
    ASSERT(rotl64(16045690984503098046ULL, 58) == 18120997243038989034ULL);
    ASSERT(rotl64(16045690984503098046ULL, 59) == 17795250412368426453ULL);
    ASSERT(rotl64(16045690984503098046ULL, 60) == 17143756751027301291ULL);
    ASSERT(rotl64(16045690984503098046ULL, 61) == 15840769428345050967ULL);
    ASSERT(rotl64(16045690984503098046ULL, 62) == 13234794782980550319ULL);
    ASSERT(rotl64(16045690984503098046ULL, 63) == 8022845492251549023ULL);
    ASSERT(rotr64(16045690984503098046ULL, 1) == 8022845492251549023ULL);
    ASSERT(rotr64(16045690984503098046ULL, 2) == 13234794782980550319ULL);
    ASSERT(rotr64(16045690984503098046ULL, 3) == 15840769428345050967ULL);
    ASSERT(rotr64(16045690984503098046ULL, 4) == 17143756751027301291ULL);
    ASSERT(rotr64(16045690984503098046ULL, 5) == 17795250412368426453ULL);
    ASSERT(rotr64(16045690984503098046ULL, 6) == 18120997243038989034ULL);
    ASSERT(rotr64(16045690984503098046ULL, 7) == 9060498621519494517ULL);
    ASSERT(rotr64(16045690984503098046ULL, 8) == 13753621347614523066ULL);
    ASSERT(rotr64(16045690984503098046ULL, 9) == 6876810673807261533ULL);
    ASSERT(rotr64(16045690984503098046ULL, 10) == 12661777373758406574ULL);
    ASSERT(rotr64(16045690984503098046ULL, 11) == 6330888686879203287ULL);
    ASSERT(rotr64(16045690984503098046ULL, 12) == 12388816380294377451ULL);
    ASSERT(rotr64(16045690984503098046ULL, 13) == 15417780227001964533ULL);
    ASSERT(rotr64(16045690984503098046ULL, 14) == 16932262150355758074ULL);
    ASSERT(rotr64(16045690984503098046ULL, 15) == 8466131075177879037ULL);
    ASSERT(rotr64(16045690984503098046ULL, 16) == 13456437574443715326ULL);
    ASSERT(rotr64(16045690984503098046ULL, 17) == 6728218787221857663ULL);
    ASSERT(rotr64(16045690984503098046ULL, 18) == 12587481430465704639ULL);
    ASSERT(rotr64(16045690984503098046ULL, 19) == 15517112752087628127ULL);
    ASSERT(rotr64(16045690984503098046ULL, 20) == 16981928412898589871ULL);
    ASSERT(rotr64(16045690984503098046ULL, 21) == 17714336243304070743ULL);
    ASSERT(rotr64(16045690984503098046ULL, 22) == 18080540158506811179ULL);
    ASSERT(rotr64(16045690984503098046ULL, 23) == 18263642116108181397ULL);
    ASSERT(rotr64(16045690984503098046ULL, 24) == 18355193094908866506ULL);
    ASSERT(rotr64(16045690984503098046ULL, 25) == 9177596547454433253ULL);
    ASSERT(rotr64(16045690984503098046ULL, 26) == 13812170310581992434ULL);
    ASSERT(rotr64(16045690984503098046ULL, 27) == 6906085155290996217ULL);
    ASSERT(rotr64(16045690984503098046ULL, 28) == 12676414614500273916ULL);
    ASSERT(rotr64(16045690984503098046ULL, 29) == 6338207307250136958ULL);
    ASSERT(rotr64(16045690984503098046ULL, 30) == 3169103653625068479ULL);
    ASSERT(rotr64(16045690984503098046ULL, 31) == 10807923863667310047ULL);
    ASSERT(rotr64(16045690984503098046ULL, 32) == 14627333968688430831ULL);
    ASSERT(rotr64(16045690984503098046ULL, 33) == 16537039021198991223ULL);
    ASSERT(rotr64(16045690984503098046ULL, 34) == 17491891547454271419ULL);
    ASSERT(rotr64(16045690984503098046ULL, 35) == 17969317810581911517ULL);
    ASSERT(rotr64(16045690984503098046ULL, 36) == 18208030942145731566ULL);
    ASSERT(rotr64(16045690984503098046ULL, 37) == 9104015471072865783ULL);
    ASSERT(rotr64(16045690984503098046ULL, 38) == 13775379772391208699ULL);
    ASSERT(rotr64(16045690984503098046ULL, 39) == 16111061923050380157ULL);
    ASSERT(rotr64(16045690984503098046ULL, 40) == 17278902998379965886ULL);
    ASSERT(rotr64(16045690984503098046ULL, 41) == 8639451499189982943ULL);
    ASSERT(rotr64(16045690984503098046ULL, 42) == 13543097786449767279ULL);
    ASSERT(rotr64(16045690984503098046ULL, 43) == 15994920930079659447ULL);
    ASSERT(rotr64(16045690984503098046ULL, 44) == 17220832501894605531ULL);
    ASSERT(rotr64(16045690984503098046ULL, 45) == 17833788287802078573ULL);
    ASSERT(rotr64(16045690984503098046ULL, 46) == 18140266180755815094ULL);
    ASSERT(rotr64(16045690984503098046ULL, 47) == 9070133090377907547ULL);
    ASSERT(rotr64(16045690984503098046ULL, 48) == 13758438582043729581ULL);
    ASSERT(rotr64(16045690984503098046ULL, 49) == 16102591327876640598ULL);
    ASSERT(rotr64(16045690984503098046ULL, 50) == 8051295663938320299ULL);
    ASSERT(rotr64(16045690984503098046ULL, 51) == 13249019868823935957ULL);
    ASSERT(rotr64(16045690984503098046ULL, 52) == 15847881971266743786ULL);
    ASSERT(rotr64(16045690984503098046ULL, 53) == 7923940985633371893ULL);
    ASSERT(rotr64(16045690984503098046ULL, 54) == 13185342529671461754ULL);
    ASSERT(rotr64(16045690984503098046ULL, 55) == 6592671264835730877ULL);
    ASSERT(rotr64(16045690984503098046ULL, 56) == 12519707669272641246ULL);
    ASSERT(rotr64(16045690984503098046ULL, 57) == 6259853834636320623ULL);
    ASSERT(rotr64(16045690984503098046ULL, 58) == 12353298954172936119ULL);
    ASSERT(rotr64(16045690984503098046ULL, 59) == 15400021513941243867ULL);
    ASSERT(rotr64(16045690984503098046ULL, 60) == 16923382793825397741ULL);
    ASSERT(rotr64(16045690984503098046ULL, 61) == 17685063433767474678ULL);
    ASSERT(rotr64(16045690984503098046ULL, 62) == 8842531716883737339ULL);
    ASSERT(rotr64(16045690984503098046ULL, 63) == 13644637895296644477ULL);
#endif				/* UINT64_MAX */
    return 0;
}
