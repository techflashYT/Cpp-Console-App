# WARNING

This is nothing but a draft of a spec for this file.  This has not been implemented yet.  

# Spec (v0.1)

These are listed in the order they appear in the file.

## Achievements

The first 16 bytes are reserved for achievements, only 12.5 of these are used, however 16 makes calculations easier, as in hex, it is `F`, the maximum 1 digit value.  

The format is binary.  0 means NOT collected, 1 means collected.  
The ids go left to right in the byte, for example, (0-7 bits, 0-15 bytes), bit 4, byte 0 is the state of achievement ID 5.  Bit 0 byte 5 is the state of achievement ID 41.  

An easy formula to calculate which bit corresponds to which achievement ID is the following:  
`Bit + (Byte * 8) + 1 = Achievement ID`  

For example: An achievements list that looks like:

```binary
Offset:             00       01       02       03       04       05       06       07       08       09       0A       0B       0C       0D       0E       0F
00000000         10000100 01000000 10000100 00100000 00000100 00010100 00001000 01000010 00100110 00100010 00100100 10000100 01000000 00000000 00000000 00000000
                                                                                                                                ^
                                                                                                                                |
                                                                                                                                |
                                                                                                            Last used bit, anything past this point is unused
```

Would mean that the folowing achievement IDs would be completed:

* 1
* 6
* 10
* 17
* 21
* 27
* 38
* 44
* 46
* 53
* 58
* 62
* 63
* 75
* 79
* 84
* 86
* 89
* 94
* 98

## Timestamp

Next, following those 16 bytes, at offset 0x00000010, there will be a UNIX style timestamp.

