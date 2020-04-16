#Project: Final Project - makefile test
#Name: Jessica Albert
#Date: 3/11/19

CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
RM = /bin/rm -f

OBJS = main.o Space.o Study.o Player.o Board.o Game.o random.o Project.o Apply.o Items.o ProfessionalContact.o Degree.o Job.o PersonalProject.o Reference.o

SRCS = main.cpp Space.cpp Study.cpp Player.cpp Board.cpp Game.cpp random.cpp Project.cpp Apply.cpp Items.cpp ProfessionalContact.cpp Degree.cpp Job.cpp PersonalProject.cpp Reference.cpp

HEADERS = Space.hpp Space.cpp Player.hpp Board.hpp Game.hpp random.hpp Project.hpp Apply.hpp Items.hpp ProfessionalContact.hpp Degree.hpp Job.hpp PersonalProject.hpp Reference.hpp

game: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o game

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	${RM} *.o main game



