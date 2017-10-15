const char httpHttp[8] = { 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f };
const char httpHttps[9] =
    { 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f };
const char http200[5] = { 0x32, 0x30, 0x30, 0x20 };
const char http301[5] = { 0x33, 0x30, 0x31, 0x20 };
const char http302[5] = { 0x33, 0x30, 0x32, 0x20 };
const char httpGet[5] = { 0x47, 0x45, 0x54, 0x20 };
const char httpTen[9] = { 0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x30 };
const char http11[9] = { 0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x31 };
const char httpContentType[15] =
    { 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20 };
const char httpLocation[11] =
    { 0x6c, 0x6f, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x20 };
const char httpHost[7] = { 0x48, 0x6f, 0x73, 0x74, 0x3a, 0x20 };
const char httpCrnl[3] = { 0xd, 0xa };
const char httpIHtm[11] =
    { 0x2f, 0x69, 0x6e, 0x64, 0x65, 0x78, 0x2e, 0x68, 0x74, 0x6d };
const char httpIndexHtml[12] =
    { 0x2f, 0x69, 0x6e, 0x64, 0x65, 0x78, 0x2e, 0x68, 0x74, 0x6d, 0x6c };
const char http404Html[10] =
    { 0x2f, 0x34, 0x30, 0x34, 0x2e, 0x68, 0x74, 0x6d, 0x6c };
const char httpReferer[9] =
    { 0x52, 0x65, 0x66, 0x65, 0x72, 0x65, 0x72, 0x3a };
const char httpHeader200[85] =
    { 0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x30, 0x20, 0x32, 0x30,
0x30, 0x20, 0x4f, 0x4b, 0xd, 0xa, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x3a, 0x20, 0x43, 0x6f,
0x6e, 0x74, 0x69, 0x6b, 0x69, 0x2f, 0x33, 0x2e, 0x78, 0x20, 0x68, 0x74, 0x74, 0x70, 0x3a,
0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x63, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0x2d, 0x6f,
0x73, 0x2e, 0x6f, 0x72, 0x67, 0x2f, 0xd, 0xa, 0x43, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x69,
0x6f, 0x6e, 0x3a, 0x20, 0x63, 0x6c, 0x6f, 0x73, 0x65, 0xd, 0xa };
const char httpHeader404[92] =
    { 0x48, 0x54, 0x54, 0x50, 0x2f, 0x31, 0x2e, 0x30, 0x20, 0x34, 0x30,
0x34, 0x20, 0x4e, 0x6f, 0x74, 0x20, 0x66, 0x6f, 0x75, 0x6e, 0x64, 0xd, 0xa, 0x53, 0x65, 0x72,
0x76, 0x65, 0x72, 0x3a, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6b, 0x69, 0x2f, 0x33, 0x2e,
0x78, 0x20, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x63, 0x6f,
0x6e, 0x74, 0x69, 0x6b, 0x69, 0x2d, 0x6f, 0x73, 0x2e, 0x6f, 0x72, 0x67, 0x2f, 0xd, 0xa, 0x43,
0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x3a, 0x20, 0x63, 0x6c, 0x6f, 0x73,
0x65, 0xd, 0xa };
const char httpContentTypePlain[29] =
    { 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x70, 0x6c, 0x61, 0x69, 0x6e, 0xd, 0xa, 0xd, 0xa };
const char httpContentTypeHtml[28] =
    { 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x68, 0x74, 0x6d, 0x6c, 0xd, 0xa, 0xd, 0xa };
const char httpContentTypeCss[27] =
    { 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x63, 0x73, 0x73, 0xd, 0xa, 0xd, 0xa };
const char httpContentTypeText[28] =
    { 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2f, 0x74, 0x65, 0x78, 0x74, 0xd, 0xa, 0xd, 0xa };
const char httpContentTypePng[28] =
    { 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x70, 0x6e, 0x67, 0xd, 0xa, 0xd, 0xa };
const char httpSubjectTypeGif[28] =
    { 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x67, 0x69, 0x66, 0xd, 0xa, 0xd, 0xa };
const char httpContentTypeJpg[29] =
    { 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x6a, 0x70, 0x65, 0x67, 0xd, 0xa, 0xd, 0xa };
const char httpSubjectTypeBinary[43] =
    { 0x43, 0x6f, 0x6e, 0x74, 0x65, 0x6e, 0x74, 0x2d, 0x74, 0x79, 0x70,
0x65, 0x3a, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x2f, 0x6f, 0x63,
0x74, 0x65, 0x74, 0x2d, 0x73, 0x74, 0x72, 0x65, 0x61, 0x6d, 0xd, 0xa, 0xd, 0xa };
const char httpHtml[6] = { 0x2e, 0x68, 0x74, 0x6d, 0x6c };
const char httpShtml[7] = { 0x2e, 0x73, 0x68, 0x74, 0x6d, 0x6c };
const char httpHtm[5] = { 0x2e, 0x68, 0x74, 0x6d };
const char httpCss[5] = { 0x2e, 0x63, 0x73, 0x73 };
const char httpPng[5] = { 0x2e, 0x70, 0x6e, 0x67 };
const char httpGif[5] = { 0x2e, 0x67, 0x69, 0x66 };
const char httpJpg[5] = { 0x2e, 0x6a, 0x70, 0x67 };
const char httpText[6] = { 0x2e, 0x74, 0x65, 0x78, 0x74 };
const char httpTxt[5] = { 0x2e, 0x74, 0x78, 0x74 };
const char httpRedirect[19] =
    { 0x3c, 0x62, 0x6f, 0x64, 0x79, 0x3e, 0x52, 0x65, 0x64, 0x69, 0x72,
0x65, 0x63, 0x74, 0x20, 0x74, 0x6f, 0x20 };
