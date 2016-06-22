function createTrees(){
  for(i = -25; i< 26; i = i + 5){
    for(j = -25; j < 26; j = j + 5){
    //Sphere
    var transformS = document.createElement('Transform');
    var shapeS = document.createElement('shape');
    var appearanceS = document.createElement('Appearance');
    var materialS = document.createElement('material');
    var sphere = document.createElement('sphere');

    
    transformS.setAttribute('translation', i + ' 1.5 ' + j);
    materialS.setAttribute('diffuseColor', '0 1 0');
    sphere.setAttribute('radius', '1.5');
    
    appearanceS.appendChild(materialS);
    shapeS.appendChild(appearanceS);
    shapeS.appendChild(sphere);
    transformS.appendChild(shapeS);
    
    //Cylinder
    var transformC = document.createElement('Transform');
    var shapeC = document.createElement('shape');
    var appearanceC = document.createElement('Appearance');
    var materialC = document.createElement('material');
    var cylinder = document.createElement('cylinder');
        
    transformC.setAttribute('translation', i + ' 0 ' + j);    
    materialC.setAttribute('diffuseColor', '#996600');
    cylinder.setAttribute('radius', '0.5');
    cylinder.setAttribute('height', '4');
    
    appearanceC.appendChild(materialC);
    shapeC.appendChild(appearanceC);
    shapeC.appendChild(cylinder);
    transformC.appendChild(shapeC);
    
    document.getElementById('theScene').appendChild(transformC);
    document.getElementById('theScene').appendChild(transformS);
  }
  } 
}