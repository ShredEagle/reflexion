from conans import ConanFile, tools
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout


from os import path


class ReflexionConan(ConanFile):
    """ Conan recipe for Math """
    """ Currently the library is header only, but there are compiled tests """
    """ so we keep the usual settings """

    name = "reflexion"
    license = "MIT"
    url = "https://github.com/shredeagle/reflexion"
    description = "A small reflexion utility library"
    topics = ("reflexion", "concept")
    settings = ("os", "compiler", "build_type", "arch")
    options = {
        "shared": [True, False],
        "build_tests": [True, False],
    }
    default_options = {
        "shared": False,
        "build_tests": False,
    }

    build_policy = "missing"
    generators = "CMakeDeps", "CMakeToolchain"


    python_requires="shred_conan_base/0.0.5@adnn/stable"
    python_requires_extend="shred_conan_base.ShredBaseConanFile"
