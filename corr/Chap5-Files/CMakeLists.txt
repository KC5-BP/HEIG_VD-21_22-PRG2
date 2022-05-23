
set( FOLDERS_USING_PERSON_DATAS
        5.03
        5.04
        5.05
)

file(GLOB 5_02_PERSON_DATAS
        "5.02/personnes.dat"
)

# Copy the file to work directly with the
# FILE* file = fopen("personnes.dat")
# instead of
# FILE* file = fopen("../whatever/shitty/path/there/is/to/personnes.dat")
foreach( FOLDER ${FOLDERS_USING_PERSON_DATAS} )
# Copy ${5_02_PERSON_DATAS} into the user dir. (a.k.a. repo/corr/Chap5-Files/...
#    file(COPY ${5_02_PERSON_DATAS}
#         DESTINATION "${PROJECT_SOURCE_DIR}/corr/Chap5-Files/${FOLDER}/")
# Copy ${5_02_PERSON_DATAS} into cmake-build-debug/ where the output is created
    file(COPY ${5_02_PERSON_DATAS}
         DESTINATION "${FOLDER}/")
endforeach()

#add_executable(5.01 5.01/helloworld.cpp)
#add_executable(5.02 5.02/.c)
#add_executable(5.03 5.03/.c)
#add_executable(5.04 5.04/.c)
#add_executable(5.05 5.05/.c)
#add_executable(5.06 5.06/.c)
#add_executable(5.07 5.07/.c)
#add_executable(5.08 5.08/.c)

