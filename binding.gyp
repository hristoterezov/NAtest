{
  'targets': [{
    'target_name': 'sourceIDToDisplay',
    'include_dirs': [
        "<!(node -e \"require('nan')\")"
    ],

    'cflags': [
      '-Wall',
      '-Wparentheses',
      '-Winline',
      '-Wbad-function-cast',
      '-Wdisabled-optimization'
    ],

    'conditions': [
      ["OS=='win'", {
        'defines': ['IS_WINDOWS']
      }]
    ],

    'sources': [
      'src/index.cc',
      'src/sourceIDToDisplay.cc'
    ]
  }]
}
