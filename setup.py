from distutils.core import setup, Extension

module = Extension(
    't',
    sources=[
        'src/int8_asnumber.c',
        'src/int8_type.c',
        'src/module.c'
    ]
)

setup(
    name = '',
    version = '0.0.1',
    description = '',
    ext_modules = [module],

    url='',
    author='',
    author_email=''
)
