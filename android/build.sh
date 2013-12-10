#!/bin/sh

rm -rf libs
gradle build

# Push to the local maven repo
mvn install:install-file -Dfile=build/libs/EmailChecker-0.1-debug.aar -DgroupId=org.wordpress -DartifactId=emailchecker -Dpackaging=aar -Dversion=0.1
