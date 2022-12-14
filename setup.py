from distutils.core import setup, Extension

module1 = Extension('sorting',
                    sources = ['sorting_ext.c', 'sorting.c'])

setup (name = 'SortingModule',
       version = '1.0',
       description = 'This is a demo package to learn C extension for Python',
       ext_modules = [module1])
