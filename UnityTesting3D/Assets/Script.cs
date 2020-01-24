using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class Script : MonoBehaviour, IPointerClickHandler
{
    // Start is called before the first frame update
    void Start()
    {
        
    }
    public void OnPointerClick(PointerEventData pointerEventData)
    {
        Debug.Log(name);
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
