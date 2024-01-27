set (CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 14)

add_library(
    brogue ${WEBROGUE_MOD_LIB_TYPE}
    
    src/brogue.c
    src/term.c
    src/webrogue-platform.c
    src/event_buffer.cpp

    external/BrogueCE/src/brogue/Architect.c
    external/BrogueCE/src/brogue/Buttons.c
    external/BrogueCE/src/brogue/Combat.c
    external/BrogueCE/src/brogue/Dijkstra.c
    external/BrogueCE/src/brogue/Globals.c
    external/BrogueCE/src/brogue/Globals.h
    external/BrogueCE/src/brogue/GlobalsBase.c
    external/BrogueCE/src/brogue/GlobalsBase.h
    external/BrogueCE/src/brogue/Grid.c
    external/BrogueCE/src/brogue/IO.c
    external/BrogueCE/src/brogue/Items.c
    external/BrogueCE/src/brogue/Light.c
    external/BrogueCE/src/brogue/MainMenu.c
    external/BrogueCE/src/brogue/Math.c
    external/BrogueCE/src/brogue/Monsters.c
    external/BrogueCE/src/brogue/Movement.c
    external/BrogueCE/src/brogue/PowerTables.c
    external/BrogueCE/src/brogue/Recordings.c
    external/BrogueCE/src/brogue/Rogue.h
    external/BrogueCE/src/brogue/RogueMain.c
    external/BrogueCE/src/brogue/SeedCatalog.c
    external/BrogueCE/src/brogue/Time.c
    external/BrogueCE/src/brogue/Utilities.c
    external/BrogueCE/src/brogue/Wizard.c

    external/BrogueCE/src/platform/platformdependent.c

    external/BrogueCE/src/variants/GlobalsBrogue.c
    external/BrogueCE/src/variants/GlobalsRapidBrogue.c
)

target_include_directories(
    brogue PRIVATE 
    external/BrogueCE/src/brogue 
    external/BrogueCE/src/platform 
    external/BrogueCE/src/variants
    src
)
target_compile_definitions(brogue PRIVATE -DBROGUE_EXTRA_VERSION="-webrogue")

register_mod(
    NAME brogue
)
