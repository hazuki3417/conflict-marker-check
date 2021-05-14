<?php

class SampleClass{

<<<<<<< HEAD
    private static string $data;
=======
    private string $data;
>>>>>>> branch-name

    public function __construct()
    {
        $this->data = 'sample';
    }

<<<<<<< HEAD
    public static function getData()
    {
        return self::$data;
    }
=======
    public function getData()
    {
        return $this->data;
    }
>>>>>>> branch-name
}
