var sourceIDToDisplay = require('./build/Release/sourceIDtoDisplay.node');

module.exports = {
  sourceIDToDisplay: function(sourceID) {
    var idArr = sourceID.split(":");
    if(idArr && idArr.length >= 1) {
        return sourceIDToDisplay.sourceIDToDisplay(parseInt(idArr[1]));
    }
    return undefined;
  }
}
