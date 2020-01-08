ALLWPI = /Users/dana/src/robot/WPI/allwpilib
INCLUDES =  -I${ALLWPI}/ntcore/src/main/native/include \
			-I${ALLWPI}/wpiutil/src/main/native/include
LIBS = \
	${ALLWPI}/ntcore/build/libs/ntcore/static/osxx86-64/release/libntcore.a  \
	${ALLWPI}/ntcore/build/libs/ntcoreBase/static/osxx86-64/release/libntcoreBase.a \
	${ALLWPI}/wpiutil/build/libs/wpiutil/static/osxx86-64/release/libwpiutil.a


testntcore:  testntcore.cpp
	clang++ ${INCLUDES} \
		-std=c++17 -stdlib=libc++ \
		testntcore.cpp -o testntcore  \
		${LIBS}