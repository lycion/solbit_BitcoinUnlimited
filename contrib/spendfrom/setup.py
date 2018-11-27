from distutils.core import setup
setup(name='sbtspendfrom',
      version='1.0',
      description='Command-line utility for solbit "coin control"',
      author='Gavin Andresen',
      author_email='gavin@solbitfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
