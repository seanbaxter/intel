circle meta1.cxx && ./meta1
circle meta2.cxx && ./meta2
circle meta3.cxx && ./meta3
circle meta4.cxx && ./meta4
circle meta5.cxx && ./meta5
circle meta6.cxx && ./meta6
circle meta7.cxx && ./meta7 # circle -S -emit-llvm meta7.cxx && more meta7.ll

# typed enums
circle enum1.cxx && ./enum1
circle enum2.cxx && ./enum2
circle enum3.cxx && ./enum3
circle enum4.cxx && ./enum4
circle enum5.cxx && ./enum5

