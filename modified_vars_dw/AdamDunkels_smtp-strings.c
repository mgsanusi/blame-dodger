const char smtp220[4] = {0x32, 0x32, 0x30};
const char smtpHelo[6] = {0x48, 0x45, 0x4c, 0x4f, 0x20};
const char smtpMailFrom[12] = {0x4d, 0x41, 0x49, 0x4c, 0x20, 0x46, 0x52, 0x4f, 0x4d, 0x3a, 0x20};
const char smtpRcptTo[10] = {0x52, 0x43, 0x50, 0x54, 0x20, 0x54, 0x4f, 0x3a, 0x20};
const char smtpData[7] = {0x44, 0x41, 0x54, 0x41, 0xd, 0xa};
const char smtpTo[5] = {0x54, 0x6f, 0x3a, 0x20};
const char smtpCc[5] = {0x43, 0x63, 0x3a, 0x20};
const char smtpFrom[7] = {0x46, 0x72, 0x6f, 0x6d, 0x3a, 0x20};
const char smtpSubject[10] = {0x53, 0x75, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x3a, 0x20};
const char smtpQuit[7] = {0x51, 0x55, 0x49, 0x54, 0xd, 0xa};
const char smtpCrnl[3] = {0xd, 0xa};
const char smtpCrnlperiodcrnl[6] = {0xd, 0xa, 0x2e, 0xd, 0xa};

