from z3 import *



result=[0x70,0x70,0xB2,0xAC,0x1,0xD2,0x5E,0x61,0x0A,0xA7,0x2A,0xA8,0x8 ,0x1C,0x86,0x1A,0xE8,0x45,0xC8,0x29,0xB2,0xF3,0xA1,0x1E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0]


result=[0x70,0x70,0xB2,0xAC,0x1,0xD2,0x5E,0x61,0x0A,0xA7,0x2A,0xA8,0x0,0x0,0x0,0x0,0x8 ,0x1C,0x86,0x1A,0xE8,0x45,0xC8,0x29,0xB2,0xF3,0xA1,0x1E,0x0,0x0,0x0,0x0]

A=[0x00,0x10,0x13,0x04,0xbf,0xbf,0xb9,0xb9,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x00,0x10,0x13,0x04,0xbf,0xbf,0xb9,0xb9,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0]

index=[2, 1, 0, 6, 5, 4, 10, 9, 8, 14, 13, 12, 255, 255, 255, 255, 2, 1, 0, 6, 5, 4, 10, 9, 8, 14, 13, 12, 255, 255, 255, 255]
v_140=[0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01,0x40,0x01]

v_160=[0x1000, 0x0001 ,0x1000 ,0x0001 ,0x1000 ,0x0001 ,0x1000 ,0x0001,0x1000,0x0001, 0x1000, 0x0001, 0x1000, 0x0001, 0x1000, 0x0001]


result_8_deshuffled_dword=[0xFF7070b2, 0xFFac01d2, 0xFF5e610a, 0xFFa72aa8,
0xFF081c86, 0xFF1ae845, 0xFFc829b2, 0xFFf3a11e]

#note that the FF means doesnt matter because the shuffle would ignore them anyway 
X1 = [ Int('x%s' % i) for i in range(16) ]
Y1 = [ Int('x%s' % i) for i in range(32) ]

#x=Int('x')
#y=Int('y')

s=Solver()

s.add( (X1[0] * v_160[0]) +(X1[1] * v_160[1] ) ==0x7070b2, (X1[0]< 0x40bf/4),(X1[1]< 0x40bf/4))
s.add( (X1[2] * v_160[2]) +(X1[3] * v_160[3] ) ==0xac01d2 ,(X1[2]< 0x40bf/4),(X1[3]< 0x40bf/4))
s.add( (X1[4] * v_160[4]) +(X1[5] * v_160[5] ) ==0x5e610a , (X1[4]< 0x40bf/4),(X1[5]< 0x40bf/4))
s.add( (X1[6] * v_160[6]) +(X1[7] * v_160[7] ) ==0xa72aa8 , (X1[6]< 0x40bf/4),(X1[7]< 0x40bf/4))
s.add( (X1[8] * v_160[8]) +(X1[9] * v_160[9] ) ==0x081c86, (X1[8]< 0x40bf/4),(X1[9]< 0x40bf/4))
s.add( (X1[10] * v_160[10]) +(X1[11] * v_160[11] ) ==0x1ae845, (X1[10]< 0x40bf/4),(X1[11]< 0x40bf/4))
s.add( (X1[12] * v_160[12]) +(X1[13] * v_160[13] ) ==0xc829b2, (X1[12]< 0x40bf/4),(X1[13]< 0x40bf/4))
s.add( (X1[14] * v_160[14]) +(X1[15] * v_160[15] ) ==0xf3a11e, (X1[14]< 0x40bf/4),(X1[15]< 0x40bf/4))
s.add(X1[8] != 126,X1[12] != 3199,X1[2]!= 2749,X1[14] != 3895,X1[10] != 427, X1[4]!= 1507,X1[6]!= 2671,X1[0]!= 1795,X1[15] != 12574,X1[13] != 14770,X1[11] != 14405,X1[9]!= 15494,X1[7]!= 15016,X1[5]!= 12554,X1[3]!= 12754,X1[1]!= 16562)
s.add(X1[8] != 127,X1[12] != 3200,X1[2]!= 2750,X1[14] != 3896,X1[10] != 428,X1[4]!= 1508,X1[6]!= 2672,X1[0]!= 1796,X1[15] != 8478,X1[13] != 10674,X1[11] != 10309,X1[9]!= 11398,X1[7]!= 10920,X1[5]!= 8458,X1[3]!= 8658,X1[1]!= 12466)


    

if s.check() == sat:
  print (s.model())

  



#[x8 = 114, x12 = 3187, x2 = 2737, x14 = 3883, x10 = 415, x4 = 1495, x6 = 2659, x0 = 1784, #0x6f8 x15  61726, x13 = 63922, x11 = 63557, x9 = 64646,x7 = 64168,x5 = 61706,x3 = 61906,x1 = 61618]

#[0x6f8,0xf0b2,0xab1,0xf1d2, 0x5d7, 61706,2659,64168, 114,64646,415,63557,3187,63922,3883,61726, ]

#result_before vpmaddwd
#a=[0xf8,0x06,0xb2,0xf0,0xb1,0xa,0xd2,0xf1,0xd7,0x5,0x0a,0xf1,0x63,0x0a,0xa8,0xfa,0x72,0x00,0x86,0xfc,0x9f,0x01,0x45,0xf8,0x73,0xc,0xb2,0xf9,0x2b,0xf,0x1e,0xf1]
#the above have signed bytes so wont work. this one below will work

#result_7=[0x00,0x7, 0xb2,0x70,0xb9,0xa,0xd2,0x71,0xdf,0x05,0xa,0x71,0x6b,0x0a,0xa8,0x7a,0x7a,0x0,0x86,0x7c,0xa7,0x01,0x45,0x78,0x7b,0x0c,0xb2,0x79,0x33,0xf,0x1e,0x71]

# problem with above is ^ that when we rollback 6 we need the word to be >0x40bf so that it can be expressed as vpmaddubsw of two bytes(max 0xFF) so we go with
#result_7= [0x703,0x40b2,0xabd,0x31d2,0x5e3,0x310a,0xa6f,0x3aa8,0x7e,0x3c86,0x1ab,0x3845,0xc7f,0x39b2,0xf37,0x311e]

#another result is
#result_7=
# 0x706,0x10b2,0xabf,0x11d2,0x5e5,0x110a,0xa71,0x1aa8,0x80,0x1c86,0x1ad,0x1845,0xc81,0x19b2,0xf39,0x111e



