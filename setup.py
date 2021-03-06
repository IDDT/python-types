from distutils.core import setup, Extension

module = Extension(
    't',
    sources=[
        'src/module.c',
        'src/i8.c',
        'src/f32.c',
        'src/i8arr_type.c',
        'src/i8arr_sequence.c'
    ]
)

setup(
    name = 't',
    version = '0.0.1',
    description = '',
    ext_modules = [module],

    url='',
    author='',
    author_email=''
)
